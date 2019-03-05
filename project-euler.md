---
description: Try something new...and solve all the challenges...
---

# Project Euler

## Problem 4

> ### Largest palindrome product
>
> #### Problem 4![](https://projecteuler.net/images/icon_info.png)
>
> A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
>
> Find the largest palindrome made from the product of two 3-digit numbers.

Since the limit is 10^6 which mean we only need to check 1998 numbers \([http://oeis.org/A050250](http://oeis.org/A050250)\)

So we can easily bruteforce, checking every product generated by production of three-digits number is palindrome number or not

 

```python
def is_palindrome(num):
	str_num = str(num)
	for i in range(0, len(str_num)):
		if str_num[i] != str_num[len(str_num) - i - 1]:
			return False
	return True

max = 0
max_i = 0
max_j = 0
for i in range(100, 1000):
	for j in range(100, 1000):
		product = i * j
		if is_palindrome(product) == True and product > max:
			max = product
			max_i = i
			max_j = j
print max, max_i, max_j
```



{% code-tabs %}
{% code-tabs-item title="output" %}
```text
906609 913 993
```
{% endcode-tabs-item %}
{% endcode-tabs %}



![](.gitbook/assets/image%20%28123%29.png)

But this is practice, so i will do it in more proper way

First, i need to wrote an algorithm to generate palindrome numbers

{% embed url="http://rhyscitlema.com/algorithms/generating-palindromic-numbers/" %}

> But it turns out that generate palindrome numbers in mathematical way is no faster than string one



## Problem 5

> ### Smallest multiple
>
> #### Problem 5![](https://projecteuler.net/images/icon_info.png)
>
> 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
>
> What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

```python
import math
def check_prime(n):
	for i in range(2, int(math.sqrt(n)) + 1):
		if n % i == 0:
			return False
	return True

def generate_prime_array(limit):
	arr = []
	for i in range(2, limit):
		if check_prime(i) == True:
			arr.append(i)
	return arr

primes = generate_prime_array(20)

k = 20
sum = 1
for p in primes:
	exp = math.floor(math.log(k)/math.log(p))
	sum *= p**exp
print sum
```

```text
232792560
```



## Problem 6

> ### Sum square difference
>
> #### Problem 6![](https://projecteuler.net/images/icon_info.png)
>
> The sum of the squares of the first ten natural numbers is,12 + 22 + ... + 102 = 385
>
> The square of the sum of the first ten natural numbers is,\(1 + 2 + ... + 10\)2 = 552 = 3025
>
> Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
>
> Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

```python
#!/bin/python

import sys

def calc(num):
    formula = (num * (num**2 - 1) * (3*num + 2))/12
    return formula
t = int(raw_input().strip())
for a0 in xrange(t):
    n = int(raw_input().strip())
    print calc(n)
```

{% code-tabs %}
{% code-tabs-item title="input" %}
```text
1
100
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="output" %}
```text
25164150
```
{% endcode-tabs-item %}
{% endcode-tabs %}
