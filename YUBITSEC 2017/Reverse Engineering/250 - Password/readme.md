- We got the file : [File](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Reverse%20Engineering/250%20-%20Password/rev2)

- After some tracing,we saw the function check_password() : 

![alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Reverse%20Engineering/250%20-%20Password/Capture.PNG)

- We can easily saw that : 
 it move 5ADh into the var_4 -> compare it with eax ( at the time it compare,eax hold values of var_14)
 
 - 5ADh = 1453 (in decimal)
 
 - So we got passwords = 1453
 
 - Flag : YUBITSEC{1453}
