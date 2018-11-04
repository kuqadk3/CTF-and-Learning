# Credits : Tuấn Linh, Phạm Nguyễn Ngọc Biên

# IDA configuration :

(Ảnh mạng)

## Problems :
![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/func_to_big.png)

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/nodes_to_big.png)

## Config :

1. IDA folder > cfg > hexrays.cfg

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/max_func.png)

2. IDA > Options > General

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/max_node.png)

# Decompile and Analysis :

- Trong khi làm bài này, IDA của mình thường xuyên bị crash, thêm vào đó mỗi lần analyse lại mất khoảng (~30 phút) với những máy có ssd, hdd như teammate của mình thì chắc cả ngày không load được file...nên mình có copy ra 2 file text hàm main() và hàm fac() là 2 hàm quan trọng để giải bài này. (File text có đính kèm trong folder github này.)

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/code_1.png)

- Ta có thể thấy ở đây khi v733 == -2013331915 thì ta sẽ có được flag, trace back v733 thì ta nhận thấy nó được write rất nhiều chỗ trong code, ở đây có thể làm chay và đọc từng chỗ nó được write, tuy nhiên một cách khác là tìm xem chỗ nào sử dụng (-2013331915), có duy nhất một chỗ khác sử dụng :

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/code_2.png)

- Trace back, ta nhận ra v1345 = argv. Và ta cần fac(argv[1]) return số khác 0 để v733 = -2013331915. Tiếp tục analyse hàm fac, ta nhận ra nó cũng được obfuscate giống hàm main(), kéo xuống dưới cùng ta thấy nó return ret_value, trace thử ret_value xem nó được write ở đâu, may mắn là chỉ có một chỗ duy nhất :

ret_value = ((~(s[v679] + s[v1297 + 2] + s[v1297 + 1] + s[v1297]) & *(&v1300 + v1297) | ~*(&v1300 + v1297) & (s[v679] + s[v1297 + 2] + s[v1297 + 1] + s[v1297])) & 0xFEC351C9 | ~(~(s[v679] + s[v1297 + 2] + s[v1297 + 1] + s[v1297]) & *(&v1300 + v1297) | ~*(&v1300 + v1297) & (s[v679] + s[v1297 + 2] + s[v1297 + 1] + s[v1297])) & 0x13CAE36) ^ (ret_value & 0xFEC351C9 | ~ret_value & 0x13CAE36);

- Tiếp tục trace v679, v1297, v1300 được write ở đâu, sau một lúc mình figure ra là :
v1297 = 0
v679 = v1297 + 3 = 3
ret_value = 0
...

- Tiếp tục tìm các biến cần, thay số vào và clean cái hàm này, bạn sẽ nhận ra : 

argv[0] + argv[1] + argv[2] + argv[3] == hard_coded_num_arr[0]
argv[1] + argv[2] + argv[3] + argv[4] == hard_coded_num_arr[1]
argv[2] + argv[3] + argv[4] + argv[5] == hard_coded_num_arr[2]
...

- Quá rõ ràng, tới đây chỉ cần z3 solve hệ phương trình 28 equations và 28 variables, trong đó đã biết "SVATTT2018{}" là flag format.

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/blank.png)

- May mắn trong team mình có ông anh ACM quá bá carry team, 3 phút code xong script giải bài này, vừa đọc doc z3 vừa code trong khi ổng chưa sài z3 bao giờ, mình vừa nói ý tưởng là ông ý code cùng xong luôn với tốc độ mình nói (code on the fly). Respect!

[Solver.py](https://raw.githubusercontent.com/kungfulon/svattt2018-writeups/master/re/giaolong/flag_solver.py) - Credits to Pham Nguyen Ngoc Bien

# Flag : SVATTT2018{0bfu5c4ti0n_m33t_VM}

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/moment_1.png)

![](https://raw.githubusercontent.com/kuqadk3/CTF-and-Learning/master/SVATTT2018/giaolong/moment_2.png)


