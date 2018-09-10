Program reads in user input (4 bytes) and xors it with data at 0x400B7E

After xoring the whole section it attempts to jump to that location and execute the instructions there

We assumed that this function would start with a normal function prologue 

push rbp
mov	rbp, rsp

We can take the opcode of this prologue (which is four bytes,554889E5) and xor that in Binary Ninja  to get the key needed to complete the challenge 

We get “C<3T” as the key. Run the program and enter that key to get the flag
ISITDTU{b4b3x0r_i5_simpl3_t4g}
