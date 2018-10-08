import binascii

def byte_to_binary(n):
    return ''.join(str((n & (1 << i)) and 1) for i in reversed(range(8)))

def hex_to_binary(h):
    return ''.join(byte_to_binary(ord(b)) for b in binascii.unhexlify(h))

base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

data = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
hex_to_bin = str(hex_to_binary(str(data)))
i = 0
encoded = ""
while i <= len(str(hex_to_bin)) - 6:
 encoded += str(base64_table[int(hex_to_bin[i:i+6],2)])
 i += 6

print encoded
