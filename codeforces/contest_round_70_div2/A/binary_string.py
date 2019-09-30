import math
T = int(raw_input(""))

def lexicographi_sort(s):
    return sorted(sorted(s), key=str.upper)

for i in range(0, T):
    x = raw_input("")
    y = raw_input("")
    tmp = bin(int(x, 2) + int(y, 2) * (2**2000))[2:][::-1]

    sorted_tmp = int(''.join(lexicographi_sort(tmp)), 2)
    print int(x, 2), int(y, 2), sorted_tmp
