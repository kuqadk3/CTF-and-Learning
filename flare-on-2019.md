---
description: 'I ended up at 67th this year, just two more until my favorite number.'
---

# Flare-On 2019

## Foreword

This blog post actually came from :

![](.gitbook/assets/image%20%28163%29.png)

So this post is actually more like summary of our discussion than a write up.

Also thanks to @bien, @nhat, @nghia, @thach.

## Level 1

Not much things to talk about, it's just a XOR

## Level 2

So basically they just passed ENCODED\_FLAG into function DECODE\_FLAG with the length is 0x1c. Length of ENCODED\_FLAG is more than 0x1c, so just patch 0x1c with a larger number that will let you to see full flag.

## Level 3

Just install the app on your Android phone and click and win.

My friend @fevral even created a z3 script...

{% code title="level2.py" %}
```python

#!/usr/bin/env python

from z3 import *

f = Real('f')
p = Real('p')
c = Real('c')

s = Solver()

s.add(0*c + 10*f - 2*p == 72,
      -c + 2*f + 4*p == 30,
      6*c - f - p == 0,
      f/p >= 2,
      f/p <= 2.5)

print s.check()
print s.model()
```
{% endcode %}

## Level 4

I just found out where it decode the flag. And wrote a python script to parse the pcap and decode the flag, another simple XOR.

{% code title="level4.py" %}
```python
from scapy.all import *

packets = rdpcap('capture.pcap')

ips = []
for packet in packets:
    ans = packet['DNS'].summary()
    #print ans
    if "DNS Ans" in ans:
        ips.append(ans.replace('''DNS Ans "''', '').replace('''"''', ""))

print ips
encoded_flag = [0x79, 0x5A, 0xB8, 0xBC, 0xEC, 0xD3, 0xDF, 0xDD, 0x99, 0xA5,
  0xB6, 0xAC, 0x15, 0x36, 0x85, 0x8D, 0x09, 0x08, 0x77, 0x52,
  0x4D, 0x71, 0x54, 0x7D, 0xA7, 0xA7, 0x08, 0x16, 0xFD, 0xD7]
flag = ['\x00'] * 30
for i in range(0, 15):
    for j in range(0, len(ips)):
        ip_addr = ips[j].strip().split('.')
        tmp1 = int(ip_addr[0])
        tmp2 = int(ip_addr[1])
        tmp3 = int(ip_addr[2])
        tmp4 = int(ip_addr[3])
        #print tmp1, tmp2, tmp3, tmp4
        if tmp1 != 127 or tmp4 & 1 or i != (tmp3 & 15):
            pass
        else:
            print i, ip_addr
            flag[2*i] = chr(tmp2 ^ encoded_flag[2*i])
            flag[2*i+1] = chr(tmp2 ^ encoded_flag[2*i+1])
print ''.join(flag) + "@flare-on.com"
```
{% endcode %}

## Level 5

Basically they just created 2 Mesh Object, overlapped. So you can just swap memory address of pointer to these 2 object and you will see the flag. Hard bullshit part is install environment to run the program.

## Level 6

We found out there are 2 ways to solve 6.

One is re-code all the program and bruteforce char by char

The another way is create a white image, and you can realize the pattern of how program embeded data in an image. And then you can do bruteforce.

## Level 7

There are many ways to solve this challenge, but basically it's all about the check

```text
if b == h
```

and dumping h.

The easy way is that you just run the program, set bp, dump .reloc and .text and md5 hash it.

When i solved this challenge, i do it in hard way. I set a bp at PyObject\_RichCompare in Python37.dll . It's a bit hard cuz

```text
== is not just == but it's also ==, >= and <=
Just joking, dont take it too serious tho, it's not ==, it's RichCompare.
```

To understand the joke, you have to read

```text
https://www.python.org/dev/peps/pep-0207/
```

Another note is that when debug Python37.dll, you can download the pdb in Installer. For some lower version of Python, Microsoft are hosting a site contains pdb for that.

Also I have to figure out how Python Lists looks like in memory, then wrote a script to patch it so that the result of every char by char comparision will return True, and dump the char in the list after every check.

## Level 8

As far as we know, there are 3 ways to solve this

1. Play to win, with the help of FCEUX emulator to slow down the program
2. Patch to win, basically the program will compare your points with 0x33, and it have 4 levels. Just patch the program or using Art Money to cheat points.
3. Assume that the flag will be printed out to screen, finding the path where they do things with PPU, patch for the program to jump into that path. In this way, you have to patch so that two screen are not overlapped and only show you part of flag. I did it this way.

## Level 9

## Level 10

Basically just run and dump the process, in the last stage i found out the XTEA algorithm, which we already met once in the SVATTT2018 Quals \(TeaVM\). Checked that by decoding the given hint image with key \[0x00, 0x00, 0x00, 0x00\] and we got an image telling us that first byte is 0x31. So basically we can just bruteforce last 3 bytes and got the flag.

## Level 11

It's register based VM. Basically ARG1 = FLARE2019 and base64 of output of calculation on ARG1 is ARG2. If you dont know it's base64, you can do a bruteforce too.

## Level 12

I grep the "@flare-on.com" string in Unicode, and found part of flag. Then guess the rest of it.

 

## Prizes

Will edit this post when I receive the prize from FireEye

![](.gitbook/assets/image%20%2899%29.png)



