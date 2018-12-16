---
description: I dont use IDA this round...
---

# Matesctf - 2018 - Round 2

## Sanity Check

```text
Rotate to find the flag:

kc1{sm}htscaX3y4ttXc_nfe

```

{% code-tabs %}
{% code-tabs-item title="solver.py" %}
```python
s = "kc1{sm}htscaX3y4ttXc_nfe"
out = ""
pos = 0
for i in range(0, len(s)):
	if i % 4 == 0 and i != 0:
		p = 5
	else:
		p = 6
	pos += p
	out += s[pos%len(s)]
print out
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="flag" %}
```text
matesctf{s4n1ty_ch3c}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

