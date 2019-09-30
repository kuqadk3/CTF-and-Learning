"""
ID: kuqadk31
LANG: PYTHON2
TASK: friday
"""

fin = open('friday.in', 'rb').read()
fout = open('friday.out', 'wb')

day = 0
day_of_month = 1

N = int(fin)
d = {}

for i in range(0, 7):
    d.update({i : 0})
d.update({5 : 1})
arr = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
#day = 13
start_day = 5
#print arr[start_day]
year = 1900
while year < 1900 + N:
    for month in range(1, 13):
        if month in [4, 6, 9, 11]:
            start_day += 30 % 7
        elif month == 2 and ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)):
            start_day += 29 % 7
            #print str(year) + " " +  "Leap"
        elif month == 2:
            start_day += 28 % 7
        else:
            start_day += 31 % 7
        start_day = start_day % 7
        d[start_day] += 1
        if year == 1900 + N - 1 and month == 12:
            d[start_day] -= 1
        if month == 12:
            year += 1
        #print arr[start_day], month + 1,  year

out = str(d[5]) + " " + str(d[6]) + " " + str(d[0]) + " " + str(d[1]) + " " + str(d[2]) + " " + str(d[3]) + " " + str(d[4]) + "\n"
fout.write(out)
