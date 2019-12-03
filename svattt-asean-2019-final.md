---
description: See ya in Cyber Sea Game 2020 (hope so)
---

# SVATTT ASEAN 2019 Final

## Foreword

Many things here are just assumption, dont take it too serious ;\)

## Network Analyzing & Defending

My strategy to defend against other teams in the contest was understanding how the bot works and generate rule based on signature of analyzed traffic but not overlap with bot's traffic. So, I have to quickly login to the server, run the dump to capture bot's traffic, before the other teams attack us.

But there are so many problems happened and the contest was delayed for 2 hours. And they even started the game when everything havent done, we don't have SSH credentials, we don't have challenge's binary...until 11 AM iirc \(!?\).

Luckily, the challenge is hard enough so that other teams couldn't solve it in first 30 mins, after received the credentials, I logged in, take a dump, but nothing there

![](.gitbook/assets/image%20%2856%29.png)

I have few ideas in mind on what happened at that moment but these 2 are most likely to happen

1. The bot login to the ssh and do something locally and since I excluded port 22, I cant capture the traffic
2. The bot is dead/no bot at all

I could have tried few things but I decided to do nothing, just took note about it. I was a bit scared that we will lose some points in earlier time in the game which will put more pressure on my team.

Later on, my team have first solve on vuln\_vm challenge \(kudos to @bien and @thach\)

![](.gitbook/assets/image%20%2840%29.png)

Since we have good beginning, I told my teammates what I found but since we are the first one who attacked other teams and havent been attacked yet so we decided to do nothing with that.

Quickly after we solved vuln\_vm, ISITDTU captured our payload and start attacking other team

![](.gitbook/assets/image%20%28116%29.png)

![](.gitbook/assets/image%20%2850%29.png)

So I start filtering some signature in payload like "cat", "base64",...It worked for a while but then this shit happened

![](.gitbook/assets/image%20%28232%29.png)

I also notice there are other exploit that was used by other team, format string

![](.gitbook/assets/image%20%28187%29.png)

I also found out that someone have dropped backdoor on our service, and it's like dead end for us because if you have a backdoor on the service, you dont have to go through the proxy \(firewall\). I was freak out but then @hung told me that it's him...phew. Kudos to @hung

![](.gitbook/assets/image%20%28248%29.png)

Other problem that I noticed is that no other team's service ever down since contest started

![](.gitbook/assets/image%20%2862%29.png)

It led me to the conclusion that "BOT WAS DIED". I told my teammates about this and they told me it's okay to try my idea since our points is 40k points higher than top 2 team at that moment

![](.gitbook/assets/image%20%2891%29.png)

So I just basically blocked all traffic...and IT WORKS!

![](.gitbook/assets/image%20%2813%29.png)

Later on, we got "ratio" solved, so basically "ratio" + "vuln\_vm" + perfect defending score == 70k points higher than top 2

![](.gitbook/assets/image%20%28155%29.png)

If I recall right, we keep perfect defending score until 4:30 PM, during that I have captured some weird things

![](.gitbook/assets/image%20%28245%29.png)

I  have discussed about this with my teammates, it looks like remcos rat traffic, which led us to 2 conclusions

1. Someone was using ngrok tcp to mirror our service and then this ngrok port was used to host remcos C&C
2. The VPS that organizer used was once C&C of remcos

Quickly calculate based on the captured traffic, I found out that this C&C have atleast a hundred clients and seems like it's from Russia

Some other teams was trying to use crontab to create backdoor on our service but then was blocked

![](.gitbook/assets/image%20%2831%29.png)

At 4:30 PM, 2 hours before the contest ended, there is a team solved "HelloVietnam", and other team captured the payload and start spreading it around. There are atleast 5 teams got that payload at that moment, I captured that one too but some how it just not work for our team...

![](.gitbook/assets/image%20%2884%29.png)

![](.gitbook/assets/image%20%28146%29.png)

Also 30 minutes later, organizer fixed the bot

![](.gitbook/assets/image%20%2853%29.png)

So many bad things happened, but it's still okay, bot is suck, other team's services was down too. And the increasing points of our team per round is equal with the 2nd team \(thanks to @hung's backdoor again, 200IQ\) and we are nearly 120k points higher than them. But then organizer decided to lower time per round so other team have a chance to win us

![](.gitbook/assets/image%20%2885%29.png)

There are so much pressure at that moment, but then @thach and @bien solved three\_o\_three. END GAME!

![](.gitbook/assets/image%20%2845%29.png)

Learning from our mistake when exploiting "vuln\_vm", I created a multi-thread script to spam other team's service so it will make it hard and take more time to find our payload. And until the contest finished, only ISITDTU can capture our payload and use it in last 2 rounds

## Final

It's a nice journey for me and my team. There is a curse that the team which won the qualification couldnt win the final. But we finally make it. GGWP.

![](.gitbook/assets/image%20%289%29.png)

Thanks @Mai\_Trần for a nice picture

![](.gitbook/assets/image%20%2810%29.png)

Just ∫du It! 4+1 in 2020 incoming

![](.gitbook/assets/image%20%28166%29.png)

