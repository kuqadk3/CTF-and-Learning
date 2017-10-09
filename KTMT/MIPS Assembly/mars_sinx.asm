    .text
    .globl main
    main:
    #Get X
    li $v0, 4
    la $a0, input_x
    syscall
    
    li $v0, 6
    syscall
    
    #save X to $f1
    mov.s $f1, $f0
    
    #Get Diff
    li $v0, 4
    la $a0, input_diff
    syscall
    
    li $v0, 6
    syscall
    
    #save Diff to $f2
    mov.s $f2, $f0
    #jal power
    
    #double n = 0;
    #	float sinx = 0;
    #	while(pow(x, (2*n + 1))/factorial(2*n+1) > diff){
    #	 sinx += pow(-1, n) * pow(x, (2*n + 1))/factorial(2*n+1);
    #		n++;
    #	}
    
    # $t0 = n
    addi $t7, $zero, 0 # t8 = 1
    # $f4 = sinx
    #l.d $f4, 0
    while:
     #calculate pow(x, 2*n + 1)
     move $t2, $t7 # move n to t2
     mul  $t2, $t2, 2 # 2n
     addi $t2, $t2, 1 # 2n + 1
     
     move $s0, $t2 # for factorial(2n+1)
     
     jal power # pow(x, 2n+1) = f3
     mov.s $f6, $f3
     
     jal factorial # (2n+1)! = v1
     #convert factorial(2n+1) = v1 = f5 to double
     mtc1 $v1, $f5
     cvt.s.w $f5, $f5
     
     #pow(-1,n)
     li $t5, 2
     div $t7, $t5
     mfhi $t6 # n%2 = t6
     
     div.s $f7, $f6, $f5 # f7 = pow(x, 2n+1)/(2n+1)!
     #mul.s $f7, $f7, $f3 # f7 = pow(-1,n) * pow(x, 2n+1)/(2n+1)!
     
     beqz $t6, plus # if(n%2 == 0) -> plus else -> minus
     neg.s $f7, $f7 # f7 = -f7
     
     plus:
      add.s $f4, $f4, $f7 # sinx += pow(-1,n) * pow(x, 2n+1)/(2n+1)!
     #plus:
      #div.s $f7, $f6, $f5 # f7 = pow(x, 2n+1)/(2n+1)!
      #mul.s $f7, $f7, $f3 # f7 = pow(-1,n) * pow(x, 2n+1)/(2n+1)!
      #add.s $f4, $f4, $f7 # sinx += pow(-1,n) * pow(x, 2n+1)/(2n+1)!
     #minus:
      #neg.s $f4, $f7, $f7 # sinx -= pow(-1,n) * pow(x, 2n+1)/(2n+1)!
      
     add $t7, $t7, 1 # n += 1
     #c.le.s $f5, $f6 # if (2n+1)! <= pow(x, 2n+1)
     div.s $f8, $f6, $f5 # f8 = pow(x, 2n+1)/(2n+1)!
     c.le.s $f2, $f8 # diff <= pow(x, 2n+1)/(2n+1)! -> while continue
     bc1t while
     
    li $v0, 4
    la $a0, output_sinx
    syscall
    
    li $v0, 2
    mov.s $f12, $f4 
    syscall
    
    #exit
    li $v0, 10
    syscall

#power : 
# x = b^n.                                         
# b in $f1.                                        
# n in $t2.                                       
# x returning value in $f3.                        

power:
 li $t5, 1
 mtc1 $t5, $f3
 cvt.s.w $f3, $f3
 #add   $t2, $t2, -1
 pow_loop: #if n($t2) > 0
  mul.s $f3, $f3, $f1 # $f3 = $f3 * $f1
  add   $t2, $t2, -1
  bgtz  $t2, pow_loop
  
  jr $ra
 
#factorial(x):
# $s0 = x
# $v1 = out_put
factorial:
     li $t0, 1
     loop:# if $s0 > 0
      mul $t0, $t0, $s0

      addi $s0, $s0, -1
      bgtz $s0, loop

     move $v1, $t0 #save return value at $v1
     jr $ra

    .data
    input_x: .asciiz "X = "
    input_diff: .asciiz "Diff = "
    output_sinx: .asciiz "\nSin(x) = "

