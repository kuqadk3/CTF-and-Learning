def insert_str(string, c, index):
    return string[:index] + c + string[index:]

arr = ['l', 'g', 'c', 'n', 'y', 'u', 'r', 'V', 'r', '3', '4', 'd', '0', 'D', 'f', '{', '_', '_', '3', '_', 'R', '}', '4', '3', 'n', 'a', '5', '0', '1']
s = ""
for c in arr:
 s += c

for i in range(len(s), 0, -1):
 last = s[len(s) -1]
 s = s[:-1]
 s = insert_str(s, last, i)

s = insert_str(s, s[len(s) - 1], 0)
s = s[:-1]
print s