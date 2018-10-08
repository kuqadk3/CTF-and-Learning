

f = open("encrypted_2","w")

secret = "***REDACTED***"
key = "JdKeVFaSdfCxZ3471ZxCVbN"


startchar = ' ' # 32
endchar = '~'   # 126
modular = ord(endchar) - ord(startchar) + 1

def encrypt(message, key):
    ret = ""
    for i in range(len(message)):
        messagechar = ord(message[i]) - ord(startchar)
        keychar = ord(key[i]) - ord(startchar)
        calculatedchar = (messagechar + keychar) % modular
        convertedchar = chr(calculatedchar + ord(startchar))
        ret += convertedchar
    return ret

f.write(encrypt(secret,key))


def decrypt(message, key):
    """
    Note, like in encrypt(message,key), the length of the message MUST equal the length of the key
    as well."""
    retn = ""

    return retn
