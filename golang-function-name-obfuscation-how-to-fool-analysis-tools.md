---
description: >-
  tldr : modifying strtab and .gopclntab to fooling analysis tools and hide your
  function's name
---

# Golang function's name obfuscation : How to fool analysis tools?

## Introduction

Golang become more widely used by malware coder these days. That's not conclusion made by me myself but from Palo Alto researchers.  They have made pretty good posts here talking about golang malware

```text
https://t.co/ITaYx2kIVP
```

And a cute picture too

![](.gitbook/assets/image%20%28222%29.png)

## Problems

As you can see in the post above, there were so much malware families coded in Golang

![](.gitbook/assets/image%20%28103%29.png)

But if you took a deeper look by clicking at those names, and read the blog about analyzing those malware, you will realize that analyzing golang malware is so easy thanks to the great tool :

```text
https://github.com/sibears/IDAGolangHelper
```

With tool like IDAGolangHelper, you can easily recover all the function names. Basically, the malware \(include those [APT28](https://www.vkremez.com/2018/12/lets-learn-dissecting-apt28sofacy.html) things\) that should take more time to reverse now can be done with just 1 click and all the function's name is "on the table". I will tell you later how this "magic" tool work, but now we should get back to those golang malware samples.

I will use a new Golang Stealer malware as an example \(thanks @VK\_Intel for providing hash of the sample\)

![](.gitbook/assets/image%20%28118%29.png)

 You can see that golang is big and it's a pain for reverse-engineer guy

![](.gitbook/assets/image%20%28115%29.png)

But then i clicked "Rename functions" on IDAGoLangHelper :

![](.gitbook/assets/image%20%28128%29.png)

And magic happened :

![](.gitbook/assets/image%20%28132%29.png)

So the question is : **How can i fool these tools ?**

## Fooling the tools

Trick to fool these tools is simple and easy : **modify .strtab and .gopclntab section**

But for explaining and answering **how and why?** questions, it will take a little bit more resources of gitbook.

Let's start by compiling a HelloWorld.go program and see its sections :

{% code-tabs %}
{% code-tabs-item title="HelloWorld.go" %}
```go
package main
import "fmt"
func main() {
    fmt.Println("hello world")
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

By using pyelf, we can view those sections :

![](.gitbook/assets/image%20%2878%29.png)

So what i want you to focus here is : **.gopclntab and .strtab**

### **Fooling IDA by modifying .STRTAB section**

By using pyelf, we know that .STRTAB start at 0x1BF420, navigate to the address, we found out that this section just basically contains all functions name, separate by a null byte

![](.gitbook/assets/image%20%287%29.png)

.STRTAB is used by tools like IDA to show the function's names if the binary is not stripped. So we can just change the function name

```text
fmt.Println -> not.Println
```

![](.gitbook/assets/image%20%2866%29.png)

And IDA will show you wrong function's name 😉 

![](.gitbook/assets/image%20%28218%29.png)

This is old trick though, but problem is that tool like IDAGolangHelper can still easily recover the function's name even if we modified .STRTAB. To answer why, we need to look deeper at the tool's code.

### Fooling IDAGolangHelper by modifying .GOPCLNTAB

Here is the code part of IDAGolangHelper where magic happens :

{% code-tabs %}
{% code-tabs-item title="Gopclntab.py" %}
```python
import idc
import idautils
import idaapi
import Utils

info = idaapi.get_inf_structure()
try:
    is_be = info.is_be()
except:
    is_be = info.mf

lookup = "FF FF FF FB 00 00" if is_be else "FB FF FF FF 00 00"

def check_is_gopclntab(addr):
    ptr = Utils.get_bitness(addr)
    first_entry = ptr.ptr(addr+8+ptr.size)
    first_entry_off = ptr.ptr(addr+8+ptr.size*2)
    addr_func = addr+first_entry_off
    func_loc = ptr.ptr(addr_func)
    if func_loc == first_entry:
        return True
    return False


def findGoPcLn():
    pos = idautils.Functions().next() # Get some valid address in .text segment
    while True:
        possible_loc = idc.FindBinary(pos, idc.SEARCH_DOWN, lookup) #header of gopclntab
        if possible_loc == idc.BADADDR:
            break
        if check_is_gopclntab(possible_loc):
            return possible_loc
        pos = possible_loc+1
    return None


def rename(beg, ptr, make_funcs = True):
    base = beg
    pos = beg + 8 #skip header
    size = ptr.ptr(pos)
    pos += ptr.size
    end = pos + (size * ptr.size * 2)
    print "%x" % end
    while pos < end:
        offset = ptr.ptr(pos + ptr.size)
        ptr.maker(pos)         #in order to get xrefs
        ptr.maker(pos+ptr.size)
        pos += ptr.size * 2
        ptr.maker(base+offset)
        func_addr = ptr.ptr(base+offset)
        if make_funcs == True:
            idc.MakeUnknown(func_addr, 1, idc.DOUNK_SIMPLE)
            idc.MakeFunction(func_addr)
        name_offset = idc.Dword(base+offset+ptr.size)
        name = idc.GetString(base + name_offset)
        name = Utils.relaxName(name)
        Utils.rename(func_addr, name)

```
{% endcode-tabs-item %}
{% endcode-tabs %}

So we can know that tool like IDAGolangHelper basically just extract information from .GOPCLNTAB section to rename the functions.

To understand what .GOPCLNTAB section is, what is it for and its structure, i have found pretty good resource, written by golang's father :

```text
https://docs.google.com/document/d/1lyPIbmsYbXnpNj57a261hgOYVpNRcgydurVQIyZOz_o/pub
```

So in hist post, .GOPCLNTAB is created because :

> To get accurate crash-time stack traces years ago, I moved the Plan 9 symbol and pc-&gt;line number \(pcln\) tables into memory that would be mapped at run time, and then I put code to parse them in the runtime package. In addition to stack traces, the stack walking ability is now used for profiling and garbage collection. This was a significant improvement on what was there before, but it has a significant drawback: the first thing a Go program does is spend time and memory allocations decoding those tables into a form that supports the kinds of queries needed during the stack walks. There has been a comment in the runtime for a long time \(on struct Func\) that says "Eventually, the loaded symbol table should be closer to this form." Doing that would make it possible to read the tables directly, eliminating the start-up time and memory costs of decoding.
>
> There are other problems with the approach too: it's a bit awkward to get new metadata from the compiler through to the runtime, because it has to be sent to the linker in one form, the linker has to encode it in the symbol table in a second form, and the runtime has to decode the new symbol table extensions. Carl has been runni ng into this with garbage collection additions. Keith also pointed out that this was a mess a month or so ago.

And we know that the function's metadata is mapped on the following struct :

```go
type _func struct {
	entry   uintptr // start pc
	nameoff int32   // function name

	args  int32 // in/out args size
	frame int32 // legacy frame size; use pcsp if possible

	pcsp      int32
	pcfile    int32
	pcln      int32
	npcdata   int32
	nfuncdata int32
}
```

So from my point of view, the function's name seems like it only be used to show user about the name of function where crash happened. And it's exactly where tools like IDAGolangHelper got function's name from. Then, it was came to my mind that why dont we modify this name if it may not cause any trouble in program :

![what\_gopclntab\_looks\_like.png](.gitbook/assets/image%20%28227%29.png)

I modified :

```text
fmt.Println => I_Pwned_You
```

![](.gitbook/assets/image%20%2859%29.png)

And after recovering function's name by IDAGolangHelper :

![](.gitbook/assets/image%20%2863%29.png)

And the program run smoothly as expected

![](.gitbook/assets/image%20%28131%29.png)

You can use this technique to obfuscate function's name, or just basically remove it, so your program is not easily reversed like those malware and AyPeeTea \(APT\). And by above struct, you can easily wrote a script to parse the .GOPCLNTAB section.

## Final

Finally, this post have come to its end \(phew\) 😅 . This post is not for supporting those malware coder, just my personal joy from researching and blogging. I hope it only be used by those who want to protect their golang source code, legally. That's also why i wrote this post based on ELF file but not Windows EXE \(though, it's not much different, on windows, it just store things on .text\). Anyway, it's just for educational purpose.

Also, sorry fellow malware researcher for making your life harder \(and my life too 🥺 \) but...

![](.gitbook/assets/image%20%28170%29.png)

