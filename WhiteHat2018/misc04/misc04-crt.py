from pwn import *
import random
import re
import libnum
context.log_level = "debug"
flag = True
while flag:
    flag = False
    io = remote("misc04.grandprix.whitehatvn.com", 1337)
    io.recv()
    '''   
    '                   Wellcom to Friendly face challenge\n'
        'According to experts, the formula for measuring the friendliness of a face is\n'
        '    (lip point**nose point)**(eyes point**forehead point) mod Face_index\n'
        '                              Now play!\n'
    '''
    text = io.recvuntil('So, what is the most friendly face?\n')
    #stage_1
    message = text.split("\n")
    module = int(message[1].split("Face_index: ")[1])
    todo = {}
    print module
    if libnum.prime_test(module):
        for mess in message[3:-2]:
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            b = pow(int(temp[3]),int(temp[4]),module-1)
            todo[temp[0]]  = pow(a,b,module)
    else:
        prime  = libnum.factorize(module)
        aaa = []
        for key, value in prime.iteritems():
            aaa.append(key)
            if value !=1:
                exit(1)
        for mess in message[3:-2]:
            bbb = []
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            for nnn in aaa:
                xxx = pow(int(temp[3]),int(temp[4]),nnn-1)
                b = pow(a,xxx,nnn)
                bbb.append(b)
            result = libnum.solve_crt(bbb,aaa)
            todo[temp[0]]  = result
    out =  sorted(todo.items(),key = lambda item:item[1])
    print out
    most = out[-1][0]
    io.sendline(most)
    print io.recv()
    io.sendline(str(out[-1][1]))
    text = io.recvuntil('So, what is the most friendly face?\n')
    #stage_2
    message = text.split("\n")
    module = int(message[1].split("Face_index: ")[1])
    todo = {}
    print module
    if libnum.prime_test(module):
        for mess in message[3:-2]:
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            b = pow(int(temp[3]),int(temp[4]),module-1)
            todo[temp[0]]  = pow(a,b,module)
    else:
        prime  = libnum.factorize(module)
        aaa = []
        for key, value in prime.iteritems():
            aaa.append(key)
            if value !=1:
                exit(1)
        for mess in message[3:-2]:
            bbb = []
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            for nnn in aaa:
                xxx = pow(int(temp[3]),int(temp[4]),nnn-1)
                b = pow(a,xxx,nnn)
                bbb.append(b)
            result = libnum.solve_crt(bbb,aaa)
            todo[temp[0]]  = result
    out =  sorted(todo.items(),key = lambda item:item[1])
    print out
    most = out[-1][0]
    io.sendline(most)
    print io.recv()
    io.sendline(str(out[-1][1]))
    #stage_3
    text = io.recvuntil('So, what is the most friendly face?\n')
    message = text.split("\n")
    module = int(message[1].split("Face_index: ")[1])
    todo = {}
    print module
    if libnum.prime_test(module):
        for mess in message[3:-2]:
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            b = pow(int(temp[3]),int(temp[4]),module-1)
            todo[temp[0]]  = pow(a,b,module)
    else:
        prime  = libnum.factorize(module)
        aaa = []
        for key, value in prime.iteritems():
            aaa.append(key)
            if value !=1:
                exit(1)
        for mess in message[3:-2]:
            bbb = []
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            for nnn in aaa:
                xxx = pow(int(temp[3]),int(temp[4]),nnn-1)
                b = pow(a,xxx,nnn)
                bbb.append(b)
            result = libnum.solve_crt(bbb,aaa)
            todo[temp[0]]  = result
    out =  sorted(todo.items(),key = lambda item:item[1])
    print out
    most = out[-1][0]
    io.sendline(most)
    print io.recv()
    io.sendline(str(out[-1][1]))
    #stage_4
    text = io.recvuntil('So, what is the most friendly face?\n')
    message = text.split("\n")
    module = int(message[1].split("Face_index: ")[1])
    todo = {}
    print module
    if libnum.prime_test(module):
        for mess in message[3:-2]:
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            b = pow(int(temp[3]),int(temp[4]),module-1)
            todo[temp[0]]  = pow(a,b,module)
    else:
        prime  = libnum.factorize(module)
        aaa = []
        for key, value in prime.iteritems():
            aaa.append(key)
            if value !=1:
                exit(1)
        for mess in message[3:-2]:
            bbb = []
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            for nnn in aaa:
                xxx = pow(int(temp[3]),int(temp[4]),nnn-1)
                b = pow(a,xxx,nnn)
                bbb.append(b)
            result = libnum.solve_crt(bbb,aaa)
            todo[temp[0]]  = result
    out =  sorted(todo.items(),key = lambda item:item[1])
    print out
    most = out[-1][0]
    io.sendline(most)
    print io.recv()
    io.sendline(str(out[-1][1]))
    #stage_5
    text = io.recvuntil('So, what is the most friendly face?\n')
    message = text.split("\n")
    module = int(message[1].split("Face_index: ")[1])
    todo = {}
    print module
    if libnum.prime_test(module):
        for mess in message[3:-2]:
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            b = pow(int(temp[3]),int(temp[4]),module-1)
            todo[temp[0]]  = pow(a,b,module)
    else:
        prime  = libnum.factorize(module)
        aaa = []
        for key, value in prime.iteritems():
            aaa.append(key)
            if value !=1:
                exit(1)
        for mess in message[3:-2]:
            bbb = []
            temp = re.split(r'\s+',mess)
            a = pow(int(temp[1]),int(temp[2]),module)
            for nnn in aaa:
                xxx = pow(int(temp[3]),int(temp[4]),nnn-1)
                b = pow(a,xxx,nnn)
                bbb.append(b)
            result = libnum.solve_crt(bbb,aaa)
            todo[temp[0]]  = result
    out =  sorted(todo.items(),key = lambda item:item[1])
    print out
    most = out[-1][0]
    io.sendline(most)
    print io.recv()
    io.sendline(str(out[-1][1]))
    print io.recv()
'''
Congrats! Flag, flag, flag!: WhiteHat{^.^_M4th_Math_Chin3se_Rema1nder_The0rem_&_Euler's_ThEorem_M@th_MAth_^/^}
'''

    # [[a0 == 81, a1 == 85, a2 == 81, a3 == 53, a4 == 79, a5 == 84, a6 == 104, a7 == 69, a8 == 78, a9 == 69, a10 == 89, a11 == 120, a12 == 81, a13 == 106, a14 == 81, a15 == 120, a16 == 77, a17 == 69, a18 == 89, a19 == 52, a20 == 81, a21 == 48, a22 == 86, a23 == 67, a24 == 78, a25 == 69, a26 == 70, a27 == 66, a28 == 78, a29 == 122, a30 == 82, a31 == 70]]
