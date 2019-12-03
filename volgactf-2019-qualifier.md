---
description: VolgaCTF - это дружба! (which mean friendship)
---

# VolgaCTF 2019 Qualifier

## RE - TrustVM

This is how program looks like in python :

```python
from functools import partial
def firstalgo(a, k):
    res = [0] * 64
    for i in range(0, 64):
        res[i] = ord(a[i]) ^ k[i]
    return res

def secondalgo(arr, rcx, shift):
    res = [0] * 64
    last = arr[63]
    for i in range(0, 64):
        first = arr[i] << rcx
        if i == 0:
            second = (last << rcx) >> 8
        else:
            second = (arr[i - 1] << rcx) >> 8
        res[(i + shift) % 64] = (first | second) % 0x100
    return res



key =[0xe1, 0xa9, 0xe1, 0x2e, 0x0b, 0x15, 0x44, 0x9c, 0x08, 0xdc, 0xdc, 0xf3, 0x1a, 0x91, 0x9c, 0x6e, 0x34, 0x5c, 0xe4, 0x5e, 0xf9, 0xe2, 0x5f, 0xf1, 0xf0, 0x86, 0x05, 0xa8, 0x70, 0x6e, 0x04, 0x53, 0x9d, 0x31, 0xec, 0x10, 0xab, 0xea, 0xf6, 0x74, 0x44, 0x79, 0x0f, 0x28, 0x53, 0x40, 0x37, 0x2c, 0x17, 0x9a, 0xc3, 0x67, 0x95, 0x2f, 0x4b, 0x27, 0xd9, 0x3f, 0xf9, 0x1d, 0x2a, 0x70, 0x77, 0x5d]

blocks = []
i = 0
inp = ""
with open('abc', 'rb') as openfileobject:
    for chunk in iter(partial(openfileobject.read, 64), b''):
            blocks.append(chunk)

encrypted = []

for block in blocks:
    firstalgo_res = firstalgo(block, key)
    rcx = 5
    shift = 9
    encrypted_block = secondalgo(firstalgo_res, rcx, shift)
    encrypted_block = ', '.join('0x%02x' % b for b in encrypted_block)
    encrypted.append(encrypted_block)
    rcx = 7
    shift = 0xd
    key = secondalgo(key, rcx, shift)
    key = firstalgo(block, key)

print encrypted
```

Thanks to @7feilee for reverse the secondalgo\(\), then we have :

{% code title="solver.py" %}
```python
from functools import partial
def firstalgo(a, k):
    res = [0] * 64
    for i in range(0, 64):
res[i] = ord(a[i]) ^ k[i]
    return res

def secondalgo(arr, rcx, shift):
    res = [0] * 64
    last = arr[63]
    for i in range(0, 64):
        first = arr[i] << rcx
        if i == 0:
            second = (last << rcx) >> 8
        else:
            second = (arr[i - 1] << rcx) >> 8
        res[(i + shift) % 64] = (first | second) % 0x100
    return res

def rev_second(arr,rcx,shift):
    res = [0] * 64
    last = arr[0]
    for i in range(0, 64):
        first = arr[i] << rcx
        if i == 64:
            second = (last << rcx) >> 8
        else:
            second = (arr[i - 1] << rcx) >> 8
        res[(i + shift) % 64] = (first | second) % 0x100
    return res

final_output = ''
# first block
out_arr = [137, 80, 78, 71, 13, 10, 26, 10, 0, 0, 0, 13, 73, 72, 68, 82, 0, 0, 2, 0, 0, 0, 2, 0, 8, 6, 0, 0, 0, 244, 120, 212, 250, 0, 0, 0, 4, 103, 65, 77, 65, 0, 0, 177, 143, 11, 252, 97, 5, 0, 0, 0, 6, 98, 75, 71, 68, 0, 255, 0, 255, 0, 255, 160]
prev = ""
print out_arr
for num in out_arr:
    prev += chr(num)
    final_output += chr(num)


def st_to_arr(st):
    arr = []
    for c in st:
        arr.append(ord(c))
    return arr
key =[0xe1, 0xa9, 0xe1, 0x2e, 0x0b, 0x15, 0x44, 0x9c, 0x08, 0xdc, 0xdc, 0xf3, 0x1a, 0x91, 0x9c, 0x6e, 0x34, 0x5c, 0xe4, 0x5e, 0xf9, 0xe2, 0x5f, 0xf1, 0xf0, 0x86, 0x05, 0xa8, 0x70, 0x6e, 0x04, 0x53, 0x9d, 0x31, 0xec, 0x10, 0xab, 0xea, 0xf6, 0x74, 0x44, 0x79, 0x0f, 0x28, 0x53, 0x40, 0x37, 0x2c, 0x17, 0x9a, 0xc3, 0x67, 0x95, 0x2f, 0x4b, 0x27, 0xd9, 0x3f, 0xf9, 0x1d, 0x2a, 0x70, 0x77, 0x5d]

count = 64
f = open('data.enc', 'rb')
content = f.read()
f.close()
for i in range(64, len(content), 64):
    enc_data = ""
    for i in range(count, count+64):
        enc_data += content[i]
    count += 64
    #reverse second algo
    rcx = 5
    shift = 9
    rcx = 8 - rcx
    shift = 64 - shift - 1
    rev_second_data = rev_second(st_to_arr(enc_data), rcx, shift)
    #print rev_second_data
    #derive key
    rcx = 7
    shift = 0xd
    derivedkey = secondalgo(key, rcx, shift)
    derivedkey = firstalgo(prev, derivedkey)
    #print derivedkey
    #decrypt
    key = derivedkey
    #print enc_data
    #print key
    #break
    tmp_rev_second_data = ''
    for i in range(0, len(rev_second_data)):
        tmp_rev_second_data += chr(rev_second_data[i])
    prev = firstalgo(tmp_rev_second_data, key)
    for i in range(0, len(prev)):
        final_output += chr(prev[i])
    tmp = ""
    for num in prev:
        tmp += chr(num)
    prev = tmp
f = open('out.png', 'wb')
f.write(final_output)
f.close()
```
{% endcode %}

Decrypt the data.enc, we got a PNG image :

![](.gitbook/assets/image%20%28216%29.png)

{% code title="flag" %}
```text
VolgaCTF{y0u_ju5t_rever5ed_a_512_b1t_Virtu4l_Mach1nE}
```
{% endcode %}

## Antifake - **Horrible Retelling**

```text
Someone sent us the news for publication. It seems an actual error, except for spelling.

"Scientists found the oldest telescope This tool was used by seafarers from Portuge. British researchers report that scientists explore Arabian sea bottom. There are a lot of wrecks. Last week one of the Scientist journal published an article about discovering a special device. It’s looks like big coin with a hole in its centre. Historians classed it as an oldest device of its tipe. Researchers suggest that it was used in middle ages or mayby earlier. One of the most special detail of telescope is a pattern rounds telescope. It includes a Picture of the Earth. At the turn of the Middle ages that was associated with a Portuguese king. There is only one same devise has been fond before. But researchers don’t sure about age of it. Altogether there are more tahn hundred same artifacts. New one isn’t most old. But its’s unique with its decoration. Besides in the latest Middle ages navigator sed more precise devices"


```



You can just paste them in google translate to read it, i guess they wrote it in Russia and then use translator to translate it to english, so it's horrible to read \(translate word by word sucks\)

And then you realize it's all talkinng about a old telescope called Astroblade

```text
VolgaCTF{astroblade}
```

## Antifake **- Fakegram Star**

We were given the instagram :

```text
https://www.instagram.com/volgactftask
```

And the posts looks like it was copy and pasted from somewhere and there is some typo problems :

```text
Me and Dan are mkin a go of it
```

Then we can see the pattern by compare fake post with original post :

```text
the (their -> ir)
fl (fling -> ing)
ag (making -> mkin)
```

Keep doing this, we can find the hidden message :

```text
theflag is we ask you to . �� make writeup for this task _
```

Flag is quite weird though :

{% code title="flag" %}
```text
VolgaCTF{weaskyoutomakewriteupforthistask}
```
{% endcode %}

## Forensic - Higher

We were given an mp3 file :

![](.gitbook/assets/image%20%2837%29.png)

The name "Higher" is a hint, basically load it in to Audacity -&gt; Effect -&gt; High-pass filter -&gt; Hipass 1500Hz

And convert to Spectrogram with maximum is 20k  :

![](.gitbook/assets/image%20%28261%29.png)

You can see a thin line \(represent 0\) and thick line \(represent 1\)

Decode it we have :

```text
VolgaCTF{N0t_4ll_c4n_b3_h34rd}
```

## Web - Shop 1

Check the robots.txt, we found :

![](.gitbook/assets/image%20%28150%29.png)

Download .war file and decompile it with JD-GUI :

![](.gitbook/assets/image%20%28197%29.png)

We found an .sql file, and it's quite interesting that someone/admin was actually use that test/test account to exploit, increase the balance to 100000000 . Though they fix it later, but my teammate and 30 team other already solved the challenge, and it gave me some ideas to solve shop 1 myself \(in intended way\) and shop 2 later

It's quite trivial that this is AutoBinding vuln, and we can pass param "Balance" as Object and control its value :

![](.gitbook/assets/image%20%28230%29.png)

And we need a POST request to change the Balance and buy Flag at the same time, using Burp Suite, we have : 

![](.gitbook/assets/image%20%2878%29.png)

Huehuehuehue :

![](.gitbook/assets/image%20%28237%29.png)

{% code title="flag" %}
```text
VolgaCTF{c6bc0c68f0d0dac189aa9031f8607dba} 
```
{% endcode %}



## Web - Shop 2

It's pretty much same though, we can find the .war file by checking robots.txt :

![](.gitbook/assets/image%20%28246%29.png)

Download and decompile .war file, we realize that no matter how much money we have, we just cant buy flag :

```java
    @RequestMapping(value={"/buy"})
    public String buy(@RequestParam Integer productId, @ModelAttribute(value="user") User user, RedirectAttributes redir, HttpServletRequest request) {
        HttpSession session = request.getSession();
        if (session.getAttribute("user_id") == null) {
            return "redirect:index";
        }
        Product product = this.productDao.geProduct(productId);
        if (product == null) {
            redir.addFlashAttribute("message", (Object)"Product not found");
            return "redirect:index";
        }
        if (product.getPrice() > user.getBalance()) {
            redir.addFlashAttribute("message", (Object)"Not enough money");
            return "redirect:index";
        }
        user.setBalance(Integer.valueOf(user.getBalance() - product.getPrice()));
        user.getCartItems().add(product);
        this.userDao.update(user);
        redir.addFlashAttribute("message", (Object)"Successful purchase");
        return "redirect:profile";
    }
```

 But it's quite easy to realize that we can do something with "cart" in /profile

```java
    @RequestMapping(value={"/profile"})
    public String profile(@ModelAttribute(value="user") User user, Model templateModel, HttpServletRequest request) {
        HttpSession session = request.getSession();
        if (session.getAttribute("user_id") == null) {
            return "redirect:index";
        }
        ArrayList cart = new ArrayList();
        user.getCartItems().forEach(p -> cart.add(this.productDao.geProduct(p.getId())));
        templateModel.addAttribute("cart", cart);
        return "profile";
    }

```

Sadly that @ModelAttribute dont set Lists so i cant do something like

```text
name=ausername&cart[0].id=4
```

But Autobind uses functions of classes too, so :

![](.gitbook/assets/image%20%283%29.png)

And we got flag :

![](.gitbook/assets/image%20%28191%29.png)

Flag :

{% code title="flag" %}
```text
 VolgaCTF{e86007271413cc1ac563c6eca0e12b62}
```
{% endcode %}





