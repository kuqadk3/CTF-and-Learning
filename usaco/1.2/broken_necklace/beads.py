"""
ID: kuqadk31
LANG: PYTHON2
TASK: beads
"""


fin = open("beads.in", "rb")
fout = open("beads.out", "wb")

fin = fin.read().split('\n')
n = int(fin[0])
s = fin[1]

#print n
def count_right(arr, ins, d):
    count = 0
    i = ins
    if arr[ins] == 'w':
        c = ins
        while arr[c%len(arr)] == 'w':
            c += 1
        arr = list(arr)
        arr[ins] = arr[c%len(arr)]
        arr = ''.join(arr)
    while d[i%len(arr)] == False and (arr[i%len(arr)] == arr[ins] or arr[i%len(arr)] == 'w'):
        #print i
        count += 1
        d[i%len(arr)] = True
        i += 1
    return count, d


def count_left(arr, ins, d):
    count = 0
    i = ins
    if arr[ins] == 'w':
        c = ins
        while arr[c%len(arr)] == 'w':
            c -= 1
        arr = list(arr)
        arr[ins] = arr[c%len(arr)]
        arr = ''.join(arr)
    while d[i%len(arr)] == False and (arr[i%len(arr)] == arr[ins] or arr[i%len(arr)] == 'w'):
        count += 1
        d[i%len(arr)] = True
        i -= 1
    return count, d

#print n, s
m = 0
tmp = 0
d = {}
count_w = 0
for i in range(0, len(s)):
    if s[i] == 'w':
        count_w += 1
    d.update({i : False})
if count_w == n:
    fout.write(str(count_w) + "\n")
    exit(0)
for i in range(0, len(s)):
    tmp_d = d.copy()
    b_count = 0
    r_count = 0
    #check bound
    cr, tmp_d =  count_right(s, i, tmp_d)
    cl, tmp_d =  count_left(s, i - 1, tmp_d)
    tmp = cr + cl
    #print i, tmp, cr, cl, tmp_d
    m = max(m, tmp)
#print m
fout.write(str(m) + "\n")
