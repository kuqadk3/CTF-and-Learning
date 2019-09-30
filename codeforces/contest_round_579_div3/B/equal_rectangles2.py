def check_even(m):
    for value in m.values():
        if value % 2 != 0:
            return False
    return True
T = int(raw_input(""))
for i in range(T):
    n = int(raw_input(""))
    arr = map(int, raw_input("").split(" "))
    total = 1
    #print arr:
    m = {}
    for i in range(0, len(arr)):
        total *= arr[i]
        if m.get(arr[i], None) == None:
            m.update({arr[i] : 1})
        else:
            m[arr[i]] += 1
    if (total ** (1/float(n))) != int(total ** (1/float(n))) or check_even(m) == False:
        print "NO"
    else:
        print "YES"
