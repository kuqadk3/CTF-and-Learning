Funny things that we found 3 ways to solve this :

1. Chinese remainder theorem

2. Partial solution

3. Wolfram alpha api (there is time-out problem, but maximum is face_index, so you can implement multiple thread + stop_point, if you found face > stop_point -> that's high likely the face you need. stop_point = 0.95 x face_index)

Wolfram alpha is quite stupid way we was thought about when it near the end of contest and 20 hours non sleep, it's so stupid that i am not gonna put it here

After 60 times, we got flag with 

[misc04-crt.py](https://github.com/kuqadk3/CTF-and-Learning/blob/master/WhiteHat2018/misc04/misc04-crt.py)

Partial solution i was learned from another teammate (which play for another team in this game) after contest look easier :

Integer(pow(Integer(pow(b,c,n)), Integer(pow(d, e, phi)), n) % n)

It was "smarter" in this case anyway lol

[another write-up](https://gist.github.com/datbmt/180f5a040fadda134d5a03c3b9de6fca)
