
def check(m, n):
    val1 = 1
    for key in m.keys():
        if m[key] % 2 != 0:
            return False
        #print key, m[key]
        val1 *= pow(key, m[key])
        #print val1, val2
    #print val1, val2
    #print (val1 ** (1/float(n * 2))), int(val1 ** (1/float(n * 2)))
    if (val1 ** (1/float(n * 2))) != int(val1 ** (1/float(n * 2))):
        return False
    return True

T = int(raw_input(""))
for i in range(T):
    n = int(raw_input(""))
    arr = map(int, raw_input("").split(" "))
    m = {}
    #print arr
    for i in range(0, len(arr)):
        if m.get(arr[i], None) == None:
            m.update({arr[i]: 1})
        else:
            m[arr[i]] += 1
    if check(m, n) == False:
        print "NO"
    else:
        print "YES"
