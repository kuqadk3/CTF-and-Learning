sign = [0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D]
cipher = [0xDE, 0x3F, 0x0F, 0x2F, 0x52, 0x4B, 0x45, 0x41, 0x65, 0x79, 0x21, 0x32]
key = []
for i in range(0, len(sign)):
	key.append(sign[i] ^ cipher[i])
# text = "adob" #adobe.org
# mess = [0x3e, 0x32, 0x39, 0x67]
# for i in range(0, len(mess)):
# 	key.append(ord(text[i]) ^ mess[i])
f = open("image.png", "rb")
content = f.read()
f.close()
print len(content)	
output = ""
print len(key)
for i in range(0, len(content)):
	c = chr(ord(content[i]) ^ key[i%len(key)])
	print hex(ord(c))
	output += c
	# c = content[i]
	# print hex(ord(c))
f = open("output1.png", "w")
f.write(output)
f.close()