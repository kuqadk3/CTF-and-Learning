inp = raw_input("").split(' ')

#print inp
n = int(inp[0])
k = int(inp[1])

for i in range(0, k):
    if n % 10 == 0:
        n = n/10
    else:
        n -= 1
    #print n
print n
