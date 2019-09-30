"""
ID : kuqadk31
LANG : PYTHON2
TASK : ride
"""
fin = open("ride.in", "rb")
fout = open("ride.out", "wb")

name_arr = fin.read().split('\n')[:-1]
comet_nums = [num - 64 for num in map(ord, name_arr[0])]
comet_num = reduce(lambda x, y: x * y, comet_nums) % 47
name_arr = name_arr[1:]

for name in name_arr:
    tmp = [num - 64 for num in map(ord, name)]
    tmp_num = reduce(lambda x, y: x * y, tmp) % 47
    if tmp_num == comet_num:
        fout.write("GO\n")
    else:
        fout.write("STAY\n")












