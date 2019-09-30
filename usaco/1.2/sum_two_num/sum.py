"""
ID: kuqadk31
LANG: PYTHON2
TASK: test
"""

fin = open('test.in', 'rb')
fout = open('test.out', 'wb')

arr = map(int, fin.read().split(' '))

fout.write(str(arr[0] + arr[1]) + '\n')
