Idea : find pgp -> pyc -> py -> crypto get the key -> pgp decrypt -> got image -> cicada3301 -> outguess -> message.txt -> flag

This iso file is quite large and painful, thanks god that my friend 7feilee wrote a script that help us to run through it and find un-usual file quickly

![](https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/Misc02/tree.PNG)

After more than 1 hour searching, we found : .pyc file and the private key file, and SaintGiong.pgp.png file in mail

7feilee was found the key : Phu_Dong_Thien_Vuong

![]https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/Misc02/7feilee.png()

Pgp decrypt with hint from organizer => we got image

![](https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/Misc02/flag.jpg)

I realize "cicada" in image file => search about stegano cicada

![](https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/Misc02/cicada3301.PNG

After some search, i found outguess => extract message.txt from image file. I was pretty luck when i open it in notepad which i immediately found a flag

![](https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/Misc02/final_flag.png)

We found it at 11 A.M, 2 hours after contest open, i was submit the flag : WHITEHATSHWSGTALI => fail

I was asked the Organizer but they told me i was wrong :lol: , lost next 5 hours trying to figure out and they just tell me sorry, they are wrong lol

Was tire and angry after that :)

I know this write up is not good but i was not intended to write a write up about this, so just copy & paste what our team discuss in slack :)
