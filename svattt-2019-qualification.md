---
description: 'Playing CTF is fun, playing CTF with friends is even better'
---

# SVATTT 2019 Qualification

## Foreword

First of all, I want to give kudos to all my team-mates who have worked hard with me during this CTF. Thanks guys!

Next, I would like to give a special thanks to our teacher, Mr Le Dinh Thanh, who have been led UET's CTF club to many achievements for years

Finally,  I want to thank VNISA, VNSecurity, Viettel and KMA for their efforts to organize this CTF contest.

Since I mostly focused on solving crypto and reverse engineer challenges during this CTF, so this write up is all about crypto and re challs

## Crypto01

```python
#!/usr/bin/env python3
from Crypto.Util.number import getPrime, inverse
SUFFIX = bytes.fromhex('2019')

def sign(message, private_key):
    m = int.from_bytes(message + SUFFIX, 'big')
    s = pow(m, private_key['d'], private_key['n'])
    return s.to_bytes((private_key['n'].bit_length()+7)//8, 'big')

def verify(signature, message, public_key):
    m = int.from_bytes(message + SUFFIX, 'big')
    s = int.from_bytes(signature, 'big')
    return pow(s, public_key['e'], public_key['n']) == m


if __name__ == '__main__':
    p = getPrime(512)
    q = getPrime(512)
    n = p*q
    e = 65537
    d = inverse(e, (p-1)*(q-1))
    private_key = {'n': n, 'e': e, 'd': d}
    public_key = {'n': n, 'e': e}
    print(public_key)
    message = bytes.fromhex(input())
    if b'cat flag' != message:
        signature = sign(message, private_key)
        print(signature.hex())
    else:
        print('Nope!')

    message = bytes.fromhex(input())
    signature = bytes.fromhex(input())

    # is this possible?
    if verify(signature, message, public_key) and message == b'cat flag':
        print(open('flag.txt').read())
```

So basically the server allow us to sign and get signature of a message if it's not "cat flag"

But still, we need signature of a message when it's "cat flag". To do so, we send to the server

```text
m = 0x63617420666c6167 + n
```

Which is not 0x63617420666c6167 but after passed to sign\(\) function, it becomes as same as if we pass m itself alone to sign\(\) function

$$
(m + n)^d \bmod n = m^d \bmod n  + n^d \bmod n = m^d \bmod n
$$

Since we got the signature that we want, just submit it and get the flag

```text
C:\Users\ADMIN\Downloads>python3 weird.py
{'n': 67761998655885843590105879625321473468665366163122885232269853261794206115615993959728990876618395362891147295986525580673528819935287958007937223416079475673811763389010403429908730637246302717985068391502324114671797895969701496401082277405620402589075870672773107039203959453532840668196065255024387368989, 'e': 65537}
607f0cce6711fdc5eca52e50b42494ab7073fe40316dfd8fd9512e7cf3eb585e4516c2331bb6461d7ebe58c968a8a7ae3852b830cd1a9795d2c76cc7cd575fe6a91b5e2fc96315f4f836d9361f930b9fca410804f2cb27837b0202313df760196c61a1434ace9dc1c799b7b0dea61292d7fa6740962c360d8c854a8a74e78984
26919cbf2c988f600a6129c2f47ad4cd07503dec89b02486e01bf4a04f8ef210a5b10db8e5c959c6fbf0fccff074243a244dbf081546e21db3b2944275b4037988077bcb629e79f3d1b2c6997df56ef5d143b8698642f3270d3ace83037dfdf6508eadf78490ffcad6db103b1e686d68072b6d74fdcf41134712da1c86a6a73f
63617420666c6167
26919cbf2c988f600a6129c2f47ad4cd07503dec89b02486e01bf4a04f8ef210a5b10db8e5c959c6fbf0fccff074243a244dbf081546e21db3b2944275b4037988077bcb629e79f3d1b2c6997df56ef5d143b8698642f3270d3ace83037dfdf6508eadf78490ffcad6db103b1e686d68072b6d74fdcf41134712da1c86a6a73f
"SVATTT{test_flag}"
```



## Crypto02

```text
#!/usr/bin/env python3
from Crypto.Util.number import getPrime, inverse
import random, math
if __name__ == '__main__':
    p = getPrime(1024)
    q = getPrime(1024)
    n = p*q
    phi_n = (p-1)*(q-1)
    e = 65537
    d = inverse(e, phi_n)
    print(n)
    secret = random.randint(0, n)
    print(pow(secret, e, n))
    # can you exploit this least significant base2019 digit oracle?
    rounds = int(2048 // math.log2(2019)) + 1
    for _ in range(rounds):
        c = int(input())
        print(pow(c,d,n) % 2019)
    m = int(input())
    if m == secret:
        print(open('flag.txt').read())
```

It's same as @ndh's write up

```text
from pwn import *
from Crypto.Util.number import getPrime, inverse
import random, math
io = remote("ip",port)
n = int(io.recvline().strip())
e = 65537
cipher = int(io.recvline().strip())
rounds = int(2048 // math.log2(2019)) + 1
m = 0
x = []
for i in range(rounds):
    c = cipher*inverse(pow(2019**i,e,n),n)
    io.sendline(str(c))
    loop = 0
    maxlen = len(x)
    for j in range(len(x)):
        loop += x[j]*inverse(2019**(maxlen-j),n)%n
    loop = loop %n% 2019
    m0 = int(io.recvline().strip())
    #m0 = pow(c,d,n)%2019
    x.append((m0-loop)%2019)
    m += ((m0-loop)%2019)*pow(2019,i)
io.sendline(str(m%n))
io.recvline()
io.recvline()
```



