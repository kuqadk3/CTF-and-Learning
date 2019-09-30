import math

def calc_comb(n):
    k = 2
    if n <= 1 :
        return 0
    elif n ==2 :
        return 1
    return math.factorial(n)/(math.factorial(n-k) * math.factorial(k))

n = int(raw_input(""))

smap = {}
tmp = ""
for i in range(0, n):
    tmp = ''.join(sorted(raw_input("")))
    if smap.get(tmp, None) == None:
        smap[tmp] = 1
    else:
        smap[tmp] += 1
count = 0
for s, num in smap.items():
    #print num
    count += calc_comb(num)
print(count)
