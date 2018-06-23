import base64 as b64
import binascii

flag = "1wMDEyY2U2YTY0M2NgMTEyZDQyMjAzNWczYjZgMWI4NTt3YWxmY="
print (binascii.hexlify(b64.b64decode(flag))[::-1]).decode('hex')