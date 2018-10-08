At first, i was thought of using some local file read to upload the shell.php but it was not.

Key here is about Symlinks :

https://en.wikipedia.org/wiki/Symbolic_link

https://0x90r00t.com/2016/02/03/hackim-2016web-400-smashthestate-write-up/

You can create symlinks file as .txt extension and point to "../../../index.php" and add it to zip file by these ubuntu command :

![alt text](https://github.com/kuqadk3/CTF-and-Learning/blob/master/root-me/web-server/File%20upload%20-%20ZIP/ubuntu_command.PNG)

Upload .zip file normally and open symlink.txt normally and got flag :

![alt text](https://github.com/kuqadk3/CTF-and-Learning/blob/master/root-me/web-server/File%20upload%20-%20ZIP/flag.PNG)



