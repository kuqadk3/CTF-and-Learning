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
(m + n)^d \bmod n = (m^d \bmod n  + n^d \bmod n ) \bmod n= m^d \bmod n
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

## RE02

Most of the re part was done by @kungfulon. Kudos to him.

Basically, the program was worked as following :

```text
1. Generate a random 32 bytes key
2. Encrypt the key with RSA hardcoded public key
3. Use the genarated key, hardcoded IV "0123456789012345" with AES-256-CBC to encrypt the file data

The file structure is as following :
1. First 5 bytes is "CRYPT"
2. Next 4 bytes is the size of rsa encrypted 32 bytes key, let call it enc_key
3. Next is enc_key
4. Next 4 bytes is the size of aes-256-cbc encrypted data, let call it enc_data
5. Next is enc_data
```

Script to decrypt the file

```text
#Kudos to @kungfulon (Bien Pham)
from Crypto.Cipher import AES
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

import struct
def file_parse(content):
	str_crypt = content[0:5]
	key_size = int(content[5:9][::-1].encode('hex'), 16)
	key_enc = content[9:9+key_size]
	data_enc_size = int(content[9+key_size:9+key_size+4][::-1].encode('hex'), 16)
	data_enc = content[9+key_size+4:9+key_size+4+data_enc_size]
	return (key_enc, data_enc)

f = open('flag.txt.rsacrypted', 'rb') #put your file here
content = f.read()
f.close()

rsa_key = RSA.importKey('''-----BEGIN RSA PRIVATE KEY-----
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
SvfBX0F+26VR
-----END RSA PRIVATE KEY-----
''')
cipher = PKCS1_OAEP.new(rsa_key)

key_enc, data_enc = file_parse(content)

key = cipher.decrypt(key_enc)

iv = '0123456789012345'
aes = AES.new(key, AES.MODE_CBC, iv)
decd = aes.decrypt(data_enc)

#remember to remove padding
f = open('out.dec', 'wb')
f.write(decd)
f.close()
```

Finally, the flag is 

```text
SVATTT{In_Wiener_we_trust}
```

## End game

Playing CTF is fun, playing CTF with friends is even better

![](.gitbook/assets/image%20%28165%29.png)

![](.gitbook/assets/image%20%28216%29.png)



