# Creds : Ariana, TuanLinh

# 1 Find ISITDTU position :
 - This is easiest part, just need to find in the enc array that enc[i] == enc[i+2] and enc[i+3] == enc[i+5] (I = I and T = T), the start pos of ISITDTU is 36
 - The S,T,U is near each other on the alphabet, so we can base on this to find m

# 2 Find m :
 - We calculate the m1 and m2 :
  
  m1 = enc[39]-enc[37] = 1110321085421447768275945874294757311370451552696385093861149689
  
  
 So m1 = enc[39] - enc[37] = enc(T) - enc(S) > 0
 And ord("T") - ord("S") = 1 or T > S
 
 Call F(x) = (m * ord(x) + i)
 
 Because m1 > 0, we can assume that F(T) and F(S) in same mod round.
 
 => m = m1
 
 # 3 Find n :
 
 m2 = enc[42] - enc[41] = F(U) - F(T) = -1204876429695607233906200723727474340332744346831302520996263862
 
 So F(U) - F(T) < 0 mean F(U) is overflowed, that's why it result F(U) < F(T) when U > T
 
 We know F(U) is overflowed, assume that it's 1 round above, then we got :
 
 n = m2 - m1 = 2315197515117055002182146598022231651703195899527687614857413551
 
 # 4 Find c :
 
 c = n*k + enc[37] - ( m * ord("S"))
 
 => bruteforce k : k = 41
 => c = 1449370084268958114154753941529504723862204623391963277996853964
 
 # 5 Generate alphabet and got flag :
 
 ![image](https://github.com/kuqadk3/CTF-and-Learning/blob/master/ISITDTU%20CTF/Love%20Cryptog/alpha.png)
