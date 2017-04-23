- We got this file : [File](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Forensic/75%20-%20Broken/file.png)

- It's seem to be broken PNG file

- So after research,i know that it lost first 16 bits : 89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52

- Adding this 16 bits into first 16 bits of file, we got fixed file :

![alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Forensic/75%20-%20Broken/fixed.png)

Flag = YUBITSEC{m4g1c_numb3rs_4r3_c00l}
