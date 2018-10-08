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
    
    li $v0, 5
    syscall
    
    #save Diff to $t2
    move $t2, $v0
    jal power

    li $v0, 2
    mov.s $f12, $f3
    syscall
    
    li $v0, 10
    syscall

#power : 
# x = b^n.                                         
# b in $f1.                                        
# n in $t2.                                       
# x returning value in $f3.                        

power:
 mov.s $f3, $f1
 add   $t2, $t2, -1
 pow_loop: #if n($t2) > 0
  mul.s $f3, $f3, $f1 # $f3 = $f1 * $f1
  add   $t2, $t2, -1
  bgtz  $t2, pow_loop
  
  jr $ra
 
       

    .data
    input_x: .asciiz "X = "
    input_diff: .asciiz "Diff = "
