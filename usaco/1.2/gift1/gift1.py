"""
ID: kuqadk31
LANG: PYTHON2
TASK: gift1
"""

fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

fin = fin.read().split('\n')

np = int(fin[0])
fin = fin[1:][:-1]
names = []
for i in range(0, np):
    names.append(fin[i])

d = {}
for i in range(0, len(names)):
    d.update({names[i] : 0})

fin = fin[np:]
#print fin
#print fin
while fin != []:
    #print fin
    l = 2
    name_giver = fin[0]
    money = int(fin[1].split(' ')[0])
    num_ppl = int(fin[1].split(' ')[1])
    if num_ppl == 0:
        fin = fin[l:]
    else:
        #print name_giver, money, num_ppl
        d[name_giver] -= money
        d[name_giver] += money % num_ppl
        money -= (money % num_ppl)
        for i in range(0, num_ppl):
        #+2 to skip first 2 line
            d[fin[i + 2].replace('\n', '')] += money/num_ppl
        #print d


        l += num_ppl
        fin = fin[l:]
out = ""
for name in names:
    out += name + " " +  str(d[name]) + "\n"

fout.write(out)
