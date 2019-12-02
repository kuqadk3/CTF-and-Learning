---
description: >-
  Sorry for not keeping my promise but I am still a little bit shy using German,
  so maybe next time idk
---

# Cyber Sea Game 2018

## Foreword

So basically it's not actual Cyber Sea Game 2018, it's just one of the Cyber Sea Game 2019 events where we have to play CTF with other players from other countries which selected randomly to solve last year challenges.  I have played and luckily won. Thanks to those new friends ;\)

## Wasm

{% file src=".gitbook/assets/main.wasm" %}

So basically this chall was released in the last hour and it's the chall that lead our team to the winning and only 1 solve during the contest. Before it was released, there were 2 reverse challenges left, one was 200 points \(this one\) and another was 300 points. So I decided to take a safe bet and solved this challenge instead of the 300 points one.

To disassemble WASM, I have used this web-based tool

```text
https://webassembly.github.io/wabt/demo/wasm2wat/
```

Disassemble the main.wasm, we got

![](.gitbook/assets/image%20%28118%29.png)

Take a quick look at the disassembled code, we realize there are 2 functions, p and q which basically work as following

```text
- p() function call the q() function
- q() function take 2 integers and doing some calculation then return 1 interger
```

So basically, I dont have to care about the calculation in q\(\) function, just re-code it in python

```text
def q(p0, p1):
	i0 = p0
	i1 = 1
	i0 <<= (i1 & 31)
	i1 = p1
	i0 ^= i1
	i1 = 24
	i0 <<= (i1 & 31)
	i1 = 24
	i0 = (i0 >> (i1 & 31))
	return i0
```

Later on, I realized the p\(\) function was took our input and passed it to q\(\) function to do the calculation, 2 chars each

![](.gitbook/assets/image%20%28160%29.png)

```text
Let's say:
- input = "abcdef"
Round 1:
q(a, b)
Round 2:
q(b, c)
Round 3:
q(c, d)
```

and then output of the q\(\) was compared with data in $d0. So I just wrote a script to bruteforce the flag char by char by knowing the flag is in "flag{}" format

```text
import string

def q(p0, p1):
	i0 = p0
	i1 = 1
	i0 <<= (i1 & 31)
	i1 = p1
	i0 ^= i1
	i1 = 24
	i0 <<= (i1 & 31)
	i1 = 24
	i0 = (i0 >> (i1 & 31))
	return i0


encoded = [0xa0, 0xb9, 0xa5, 0xb5, 0x81, 0xdd, 0x55, 0x55, 0x04, 0x9b, 0xdf, 0xb1, 
  0x95, 0xd5, 0x0b, 0xb8, 0xa8, 0xa1, 0xad, 0x8f, 0x11, 0xb9, 0xcd, 0xd6, 
  0x3f, 0xd9, 0xfe, 0x50, 0x50, 0x50, 0x04, 0xb5, 0xfa]

flag = "f"
pos = 0
while flag[len(flag) - 1] != "}":
	for c in string.printable:
		if q(ord(flag[pos]), ord(c)) == encoded[pos]:
			flag += c
			print flag
			pos += 1
			break
```

Later on, I realized there is tool that can convert wasm to C \([https://github.com/WebAssembly/wabt](https://github.com/WebAssembly/wabt)\). I tried some but all failed, this one worked

```text
import string

def q(p0, p1):
	i0 = p0
	i1 = 1
	i0 <<= (i1 & 31)
	i1 = p1
	i0 ^= i1
	i1 = 24
	i0 <<= (i1 & 31)
	i1 = 24
	i0 = (i0 >> (i1 & 31))
	return i0


encoded = [0xa0, 0xb9, 0xa5, 0xb5, 0x81, 0xdd, 0x55, 0x55, 0x04, 0x9b, 0xdf, 0xb1, 
  0x95, 0xd5, 0x0b, 0xb8, 0xa8, 0xa1, 0xad, 0x8f, 0x11, 0xb9, 0xcd, 0xd6, 
  0x3f, 0xd9, 0xfe, 0x50, 0x50, 0x50, 0x04, 0xb5, 0xfa]

flag = "f"
pos = 0
while flag[len(flag) - 1] != "}":
	for c in string.printable:
		if q(ord(flag[pos]), ord(c)) == encoded[pos]:
			flag += c
			print flag
			pos += 1
			break
```

![](.gitbook/assets/image%20%2889%29.png)

```text
flag{w333b_ass3mbly_1s_s0_g0000d}
```

## End game

The winning team got a small souvenir from ETDA, thanks ETDA ;\)

It's pretty sad that I have not taken any picture with my new team :\( Too bad, maybe next year...

![](.gitbook/assets/image%20%282%29.png)

