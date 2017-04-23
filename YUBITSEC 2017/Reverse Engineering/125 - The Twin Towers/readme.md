- We got class file : [File](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Reverse%20Engineering/125%20-%20The%20Twin%20Towers/Wtf.class)

- You can decompile it with : http://www.javadecompilers.com and got the decompiled file : [Decompiled File](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Reverse%20Engineering/125%20-%20The%20Twin%20Towers/decompiled.txt)

- The decompiled file have the flag() function,after look at it, we will realize that we can execute this function alone :

![alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/YUBITSEC%202017/Reverse%20Engineering/125%20-%20The%20Twin%20Towers/Capture.PNG)

- After execute flag() function with ideone.com - [Ideone](http://ideone.com/MKtTfQ), we got : 59554249545345437B77686F5F757365735F6A6176615F696E5F323031377D

- It's hex -> string : YUBITSEC{who_uses_java_in_2017}
