---
description: 'Sleep first, CTF second.'
---

# BSidesSF 2019 CTF

## Forensic - bWF0cnlvc2hrYQ==

### Foreword

The challenge is easy, not sure why it have high points, maybe because it have too much stages that make you frustated

### Just fucking solve it!

Decode challenge's name by base64decode, we got

```text
matryoshka
```

So i can imagine that this one have many stage to solve

![](.gitbook/assets/galshir-babushka.gif)

So the challenge gave us an eml file

{% file src=".gitbook/assets/bwf0cnlvc2hryq.eml" %}

Extract the eml file, we found the message and attachments

![](.gitbook/assets/image%20%2823%29.png)

We was given Matry\_Oshka.key as PGP public key

```text
root@kali:~/Desktop/tmp/bside_sf/matryoska# cat Matry_Oshka.key
-----BEGIN PGP PRIVATE KEY BLOCK-----

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
=Hhg6
-----END PGP PRIVATE KEY BLOCK-----
```

Where hack.pgp is encrypted data

Later we found the QR code

![](.gitbook/assets/image%20%28168%29.png)

It was too small, so some online qr decoder fail, my experience for this is, if you cant decode with your computer software, use phone. Which successfully decoded it

```text
h4ck_the_plan3t
```

Then i use PGPTool to decode hack.pgp with that password

![](.gitbook/assets/image%20%2819%29.png)

{% file src=".gitbook/assets/hack4.zip" %}

Inside hack4.zip, we found file.bin

```text
root@kali:~/Desktop/tmp/bside_sf/matryoska# file file.bin
file.bin: data
root@kali:~/Desktop/tmp/bside_sf/matryoska# binwalk file.bin

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
11            0xB             lzip compressed data, version: 1
```

So there is lzip compressed data, let view it in hex

![](.gitbook/assets/image%20%28148%29.png)

So i assume first 11 bytes is trash, i delete it and export the file

```text
root@kali:~/Desktop/tmp/bside_sf/matryoska# file file.bin
file.bin: lzip compressed data, version: 1
root@kali:~/Desktop/tmp/bside_sf/matryoska/tmp# lzip -d file.bin
root@kali:~/Desktop/tmp/bside_sf/matryoska/tmp# ls
file.bin.out
root@kali:~/Desktop/tmp/bside_sf/matryoska/tmp# file file.bin.out
file.bin.out: PDF document, version 1.3
```

Well, it's an PDF document

![](.gitbook/assets/image%20%2861%29.png)

Analze the pdf stream, deflated it and we got junk, bad image .\_. I was thought it's because of resolution

![](.gitbook/assets/image%20%2836%29.png)

With good pair of eyes, you can see there is QR code hidden in this image

By using StegSolver subtract, and found the original image online 

```text
https://en.wikipedia.org/wiki/Bliss_(image)
```

you can trivially extract the QR code

![](.gitbook/assets/image%20%2827%29.png)

Next, i was spent 2 hours cluelessly finding a way to recover the QR...

I have no progress, so i need to come back and look again all step i did, then i was figured out that the image in PDF is already messed up when i extracted it

![](.gitbook/assets/tenor.gif)

Extract it properly again, i found an 162kb \(if i recall it right\) image instead of 121kb. Then just do pixel subtract.

![](.gitbook/assets/image%20%2814%29.png)

{% file src=".gitbook/assets/solved.bmp" %}

Decode the QRcode, we got

```text
/Td6WFoAAATm1rRGAgAhARwAAAAQz1jM4ELCAORdABhgwwZfNTLh1bKR4pwkkcJw0DSEZd2BcWATAJkrMgnKT8nBgYQaCPtrzORiOeUVq7DDoe9feCLt9PG-MT9ZCLwmtpdfvW0n17pie8v0h7RS4dO/yb7JHn7sFqYYnDWZere/6BI3AiyraCtQ6qZmYZnHemfLVXmCXHan5fN6IiJL7uJdoJBZC3Rb1hiH1MdlFQ/1uOwaoglBdswAGo99HbOhsSFS5gGqo6WQ2dzK3E7NcYP2YIQxS9BGibr4Qulc6e5CaCHAZ4pAhfLVTYoN5R7l/cWvU3mLOSPUkELK6StPUBd0AABBU17Cf970JQABgALDhQEApzo4PbHEZ/sCAAAAAARZWg==
```

Decode it, we have something looks like an 7z file

![](.gitbook/assets/image%20%287%29.png)

{% file src=".gitbook/assets/out.7z" %}

Extract out.7z, we got out.bin which contains a lot of binary string

Do decode as following

```text
binary-ascii-octal-ascii-decimal-hex-ascii
```

We got base64 string

```text
Nlc/TyVBN11SY0ZDL2EuP1lzcSFCallwdERmMCEz
```

Which decode to

```text
echo "Nlc/TyVBN11SY0ZDL2EuP1lzcSFCallwdERmMCEz" | base64 -d
6W?O%A7]RcFC/a.?Ysq!BjYptDf0!3
```

Which is ascii85 encode

![](.gitbook/assets/image%20%28166%29.png)

```text
CTF{delat_iz_muhi_slona}
```

