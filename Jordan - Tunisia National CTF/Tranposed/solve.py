import random

def solve_2(str):
 f1 = str[0:len(str)/2]
 f2 = str[len(str)/2:]
 f = ""
 for i in range(0, len(f1)):
  f += f1[i] + f2[i]
 return f

def solve_1(l):
 return l[-1] + l[:-1]

def solve_3_main(encode, perm, W):
 s = ""
 for i in range(0, len(encode), W):
  part_encode = encode[i:i+W]
  s += ''.join(solve_3(part_encode, perm))
 return s

def solve_3(encode, perm):
 decode = ['x']*len(encode)
 for i in range(0, len(perm)):
  decode[perm[i]] = encode[i]
 return decode

W = 7

for i in range(0, 10000):
 encode = "L{NTP#AGLCSF.#OAR4A#STOL11__}PYCCTO1N#RS.S"
 perm = range(W)
 random.shuffle(perm)
 for i in xrange(100):
  encode = solve_3_main(encode, perm, W)
  encode = solve_1(encode)
  encode = solve_2(encode)
  encode = solve_1(encode)
 if('FLAG' in encode):
  print perm
  print encode
  break
