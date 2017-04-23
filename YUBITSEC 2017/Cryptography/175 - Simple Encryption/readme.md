It give us 

 - [Encrypt code](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Cryptography/175%20-%20Simple%20Encryption/simple_enc.py) which coded in python
 
 - [Encrypted message](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Cryptography/175%20-%20Simple%20Encryption/encrypted.txt)
 
 - Basically,it just change the char -> ascii number -> xor with 62 -> encrypted number
 
 - So ,to reverse this , we need : encrypted number -> xor with 62 -> ascii number -> char . Because
 
b=0011 (3)            a=0101 (5)

c=0110 (6) XOR   or   c=0110 (6) XOR

----------            ----------

a=0101 (5)            b=0011 (3)

- You can just use their encrypt.py to decode or here i coded the decoder in c++ [Decoder C++](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Cryptography/175%20-%20Simple%20Encryption/decode.cpp)

- Run it, and we got : 
![alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Cryptography/175%20-%20Simple%20Encryption/got.PNG)

Flag = YUBITSEC{well_great}
