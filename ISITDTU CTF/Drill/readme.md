# Creds : Dutchen18, TuanLinh, Ariana

# 1. Fix the zip file :
![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/fix_zip.PNG)

# 2. Extract and brute force password of all zip :

I wrote the script multiple_unzip.py, use fcrackzip and unzip on ubuntu to extract 500 zip file with rockyou wordlist and 500-worst-password worst list. The 500-worst to solve the first zip, password is boston, other zip is ok with rockyou

![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/multiple_unzip.png)

Unzip till 0.zip :

![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/ubuntu.png)

# 3. Got key.png and box.zip :

Inside the box.zip, there is flag.txt

![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/box.png)

Key is inside key.png, the red dots in picture is morse code, i wrote python code to read it :

![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/morse.png)

Extract box.zip with decoded morse, we got final flags :

![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Drill/final.png)

