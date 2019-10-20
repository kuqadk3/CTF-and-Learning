---
description: Wait for others write up...soon
---

# Matesctf - 2019 - Round 3

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

![out.gif](.gitbook/assets/image%20%2835%29.png)

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
matesctf{0ld_sch00l_w1r3t4pp1n9}
```
{% endcode-tabs-item %}
{% endcode-tabs %}



## Pwn 03

You just need to choose first 4 numbers, and spam with 3-4 tabs

![](.gitbook/assets/image%20%28144%29.png)

The generated numbers array will be the same

![](.gitbook/assets/image%20%2891%29.png)

And you will get flag with a little bit luck

![](.gitbook/assets/image%20%2880%29.png)

Double confirmed

![](.gitbook/assets/image%20%2895%29.png)

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



## Crypto 01

Lazy ass write up

```text
err=40
p2p3=25718339416197155016347059200722990565554067870853545610226371966653516052382546957914320289812433453859436193345068829987610976923180252683267226804850952829 
p1p4=25718339416197155016347059200722990565554067870853545610226371966653516052380672185338246396962573998431009659213305660299083786739031942533878562393814187971
p1_approx=isqrt(p1p4/1000000)
p4_approx=1000000*p1_approx+2**err
F.<x>=PolynomialRing(Zmod(p1p4),implementation='NTL')
f=x-p4_approx
d=f.small_roots(X=2**err,beta=0.5)
d=d[0]
p4=p4_approx-d
p1=int(p1p4)/int(p4)
p2_approx=isqrt(p2p3/100)
p3_approx=100*p2_approx+2**err
F.<x>=PolynomialRing(Zmod(p2p3),implementation='NTL')
f=x-p3_approx
d=f.small_roots(X=2**err,beta=0.5)
d=d[0]
p3=p3_approx-d
p2=int(p2p3)/int(p3)
print('p1',p1)
print('p2',p2)
print('p3',p3)
print('p4',p4)
```



```python
from sympy import integer_nthroot


def execute(key):
        a, exact = integer_nthroot(key, 2)
        while 1:
            b2 = a*a - key
            if b2 >= 0:
                b, exact = integer_nthroot(b2,2)
                if b*b == b2:
                    break
            a += 1
        p = a+b
        q = a-b
        return True, p, q
print execute(661432982326720220312000264055749897099634058126069682916663983164095399891922239185277584515989571021804685855667350963576552884237075033389449261228025690631313796676189863627781905258968287175185368245091537181600636083142076805504788733126704459028930388517968658736636444935785049391422022025814770038260219959)

```



```python
import gmpy2
p1=5071325213018502032453535422233044521528479117204265797128632927817941444209
p2=507132521301850203245353542223304452152847911720426579712863292781794144420937
p3=50713252130185020324535354222330445215284791172042657971286329278179414442093717
p4=5071325213018502032453535422233044521528479117204265797128632927817941444209372019

c=65730544585056113196855222491649915283458030302678764492256366948316495562844164405260875181381605385931592293174537287502809335112362051614031281550069787125630668940406746065617547709904187617743835592204030473969255847562554773875593313128402311178757607880009338508747805647372484237195480768305231875020498766
e=65730544585056113196855222491649915283458030302678764492256366948316495562844164405260875181381605385931592293174537287502809335112362051614031281550069787125630668940406746065617547709904187617743835592204030473969255847562554773875593313128402311178757607880009338508747805647372484237195480768305231875020498766
phip=(p1-1)*(p2-1)*(p3-1)*(p4-1)
p=p1*p2*p3*p4
e=65537
d=gmpy2.invert(e,phip)
print hex(pow(c,d,p))[2:].decode('hex')


```

![](.gitbook/assets/image%20%2879%29.png)

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
matesctf{rsa_is_fun_cryptography}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

## Web 01 + 02 + 03

God \(ノ ゜Д゜\)ノ ︵ ┻━┻

```text
https://movrment.blogspot.com/2019/02/matesctf-s3r3-web-123.html?fbclid=IwAR1TjOTcacohYjhT3iHC-OTcV28dAFwRvrHqHmJV-W4y1v-tpSmRqullCrk
```



