---
description: Wait for others write up...soon
---

# Matesctf - 2018 - Round 3

## Forensic 01

By looking at pattern of numbers in log file, we found the function :

```text
a = [16 ,4 ,23 ,8 ,22 ,6 ,23 ,9 ,225 ,47 ,14 ,8 ,28 ,15 ,18 ,10 ,225 ,45 ,23 ,11 ,30 ,22 ,225 ,45 ,14 ,32 ,28 ,15 ,18 ,10 ,225 ,45 ,23 ,11 ,33 ,23 ,225 ,48]
b = [(e+ord('a')-4) % 256 for e in a]
print ''.join(map(chr,b))
```

Output :

```text
matesctf>�keylog>�th{s>�k}ylog>�th~t>�
```

With a little bit guessing :

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
matesctf{keylog_th1s_k3ylog_th4t}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

## Forensic 02

```text
root@HACK_THE_PLANET:/home/tuanlinh/Desktop/all_stuff# minimodem -r -f d0bstep.wav 300 > out.gif
### CARRIER 300 @ 1250.0 Hz ###

### NOCARRIER ndata=2233 confidence=2.333 ampl=0.992 bps=300.00 (rate perfect) ###
```

Flag :

![out.gif](.gitbook/assets/image%20%2821%29.png)

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
matesctf{0ld_sch00l_w1r3t4pp1n9}
```
{% endcode-tabs-item %}
{% endcode-tabs %}



## Pwn 03

You just need to choose first 4 numbers, and spam with 3-4 tabs

![](.gitbook/assets/image%20%2887%29.png)

The generated numbers array will be the same

![](.gitbook/assets/image%20%2856%29.png)

And you will get flag with a little bit luck

![](.gitbook/assets/image%20%2849%29.png)

Double confirmed

![](.gitbook/assets/image%20%2859%29.png)

{% code-tabs %}
{% code-tabs-item title="solver.py" %}
```python
from pwn import *

while True:
	r = remote('125.235.240.168', 20191)
	r.recvuntil('Your choice: ')
	r.send("2\n")
	if "WIN" in r.recvuntil('Your choice: '):
		r.send("2\n")
		if "WIN" in r.recvuntil('Your choice: '):
			r.send("3\n")
			if "WIN" in r.recvuntil('Your choice: '):
				r.send("1\n")
				if "WIN" in r.recvuntil('Your choice:'):
					r.interactive()
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
MatesCTF{YE5_Y0U_34RN3D_TRU3_FLAG}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

