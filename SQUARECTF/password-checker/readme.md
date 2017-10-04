Một bài khá hay,học được thêm một vài thứ.

Đề Bài :

![Alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/SQUARECTF/password-checker/de_bai.PNG)

Ở bài này thì các lệnh 

ls

cat

-> đều không có tác dụng

- Đầu tiên khi mình thử ls -la ../ thì tìm được fake flag thứ nhất :

![Alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/SQUARECTF/password-checker/ls.PNG)

- Tiếp đó sử dụng cat ../flag.txt thì tìm được fake flag thứ hai :

![Alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/SQUARECTF/password-checker/fake.PNG)

-> Lúc này thực sự khá nản cơ mà lúc nhập cái flag này vào thì đưa tới link một bài hát [!Never Gonna Give You Up
](https://www.youtube.com/watch?v=dQw4w9WgXcQ) =]] Nhạc khá hay nên vừa nghe vừa ngồi nghĩ tiếp
- Sau một hồi google thì tìm ra cách dùng echo */* (thực ra toàn quen cat với ls, giờ mới biết cái này) -> hiển thị tất cả các file/folder :

![Alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/SQUARECTF/password-checker/flag.PNG)

- Flag : cat /sbin/wipefs/secrets/flag /

![Alt tag](https://github.com/kuqadk3/CTF-and-Learning/blob/master/SQUARECTF/password-checker/final.PNG)

- flag-rytez-cesev-feheb-fures-dakyd
