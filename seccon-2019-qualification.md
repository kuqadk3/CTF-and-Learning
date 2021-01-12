# SECCON 2019 - Qualification

## PPKeyboard

![](.gitbook/assets/image%20%28229%29%20%282%29.png)

We were given two file, **PPKeyboard.exe** and **packets.pcapng**

Take a quick look at **packets.pcapng**, we realize there is device connected and communicated through USB

![](.gitbook/assets/image%20%2859%29.png)

Since the exe file's name is **PPKeyboard.exe**, we can guess it's a keyboard. Actually, it's MIDI keyboard. Actually, it's Electronic Piano keyboard. \(If you curious why, take a look at MIDI's message/protocol here [http://www.music-software-development.com/midi-tutorial.html](http://www.music-software-development.com/midi-tutorial.html) , though knowledge about MIDI message/protocol is not required to solve this challenge\)

The **PPKeyboard.exe** first check if there is any available MIDI devices. If there is any, it will try to open the device

![](.gitbook/assets/image%20%2889%29.png)

Quick search on MSDN, we find out definition of **midiInOpen**

```cpp
MMRESULT midiInOpen(
  LPHMIDIIN phmi,
  UINT      uDeviceID,
  DWORD_PTR dwCallback,
  DWORD_PTR dwInstance,
  DWORD     fdwOpen
);
```

What important here is callback function **sub\_7FF792A01070**

![](.gitbook/assets/image%20%28224%29.png)

Take a look at **sub\_7FF792A01070**, we easily realize it's parsing somewhat data in **a4**

![](.gitbook/assets/image%20%28125%29.png)

We take a quick look back at the pcapng file, and filter out those packets that contains data

![](.gitbook/assets/image%20%28138%29.png)



So basically the callback function **sub\_7FF792A01070** is created to handle those MIDI's messages and print out a hex string. Since they compare **a4 &gt; 0x7F0000**, so I was thinking that we have to change the byte's order

```text
Ex : 97047f -> 7f0497
```

So I just dump the pcapng to csv and wrote a python script to parse and re-order the data

{% file src=".gitbook/assets/seccon\_midi.csv" %}

{% code title="dumper\_csv.py" %}
```python
import csv

def parse_st(s):
	return '0x' + s[6] + s[7] + s[4] + s[5] + s[2] + s[3]
arr = []
arr_channel = []
with open('seccon_midi.csv', 'rb') as csv_file:
	csv_reader = csv.reader(csv_file, delimiter=',')
	line_count = 0
	for row in csv_reader:
		arr.append(row[6])

arr = arr[1:]
arr_parsed = []
for i in range(0, len(arr)):
	arr_parsed.append(parse_st(arr[i]))

arr2 =[]
for i in range(0, len(arr_parsed)):
	tmp = int(arr_parsed[i], 16)
	if tmp > 0x7F0000:
		arr2.append(hex(tmp))
print len(arr)
print str(arr2).replace('\'', '')
```
{% endcode %}

So it's pretty trivial from now on, just quickly recode the callback function

{% code title="callback.cpp" %}
```cpp
#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
	unsigned int arr[268] = { 0x7f0497, 0x7f0899, 0x7f0697, 0x7f0599, 0x7f0797, 0x7f0999, 0x7f0297, 0x7f0099, 0x7f0697, 0x7f0799, 0x7f0797, 0x7f0599, 0x7f0797, 0x7f0999, 0x7f0797, 0x7f0399, 0x7f0297, 0x7f0199, 0x7f0297, 0x7f0099, 0x7f0497, 0x7f0699, 0x7f0497, 0x7f0c99, 0x7f0497, 0x7f0199, 0x7f0497, 0x7f0799, 0x7f0297, 0x7f0099, 0x7f0697, 0x7f0999, 0x7f0797, 0x7f0399, 0x7f0297, 0x7f0099, 0x7f0597, 0x7f0399, 0x7f0497, 0x7f0599, 0x7f0497, 0x7f0399, 0x7f0497, 0x7f0399, 0x7f0497, 0x7f0f99, 0x7f0497, 0x7f0e99, 0x7f0797, 0x7f0b99, 0x7f0397, 0x7f0399, 0x7f0697, 0x7f0e99, 0x7f0397, 0x7f0799, 0x7f0397, 0x7f0399, 0x7f0797, 0x7f0299, 0x7f0397, 0x7f0399, 0x7f0697, 0x7f0499, 0x7f0597, 0x7f0f99, 0x7f0697, 0x7f0699, 0x7f0797, 0x7f0299, 0x7f0397, 0x7f0099, 0x7f0697, 0x7f0d99, 0x7f0597, 0x7f0f99, 0x7f0397, 0x7f0799, 0x7f0697, 0x7f0899, 0x7f0397, 0x7f0399, 0x7f0597, 0x7f0f99, 0x7f0797, 0x7f0099, 0x7f0397, 0x7f0399, 0x7f0797, 0x7f0299, 0x7f0697, 0x7f0699, 0x7f0397, 0x7f0099, 0x7f0797, 0x7f0299, 0x7f0697, 0x7f0d99, 0x7f0397, 0x7f0499, 0x7f0697, 0x7f0e99, 0x7f0697, 0x7f0399, 0x7f0397, 0x7f0399, 0x7f0597, 0x7f0f99, 0x7f0797, 0x7f0099, 0x7f0397, 0x7f0499, 0x7f0697, 0x7f0499, 0x7f0597, 0x7f0f99, 0x7f0697, 0x7f0b99, 0x7f0397, 0x7f0399, 0x7f0797, 0x7f0999, 0x7f0697, 0x7f0299, 0x7f0397, 0x7f0099, 0x7f0397, 0x7f0499, 0x7f0797, 0x7f0299, 0x7f0697, 0x7f0499, 0x7f0797, 0x7f0d99 };
	for (int i = 0; i < 268; i++) {
		unsigned int a4 = arr[i];
		if ((unsigned __int8)a4 == 0x97) {
			printf("%x", ((a4 & 0xFFF) - 0x97) >> 8);
		}
		else if ((unsigned __int8)a4 == 0x99) {
			printf("%x", ((a4 & 0xFFF) - 0x99) >> 8);
		}
	}
	return 0;
}
```
{% endcode %}

We got a hex string

```text
48657920677579732120464c414720697320534543434f4e7b336e37337233645f6672306d5f3768335f7033726630726d346e63335f7034645f6b337962303472647d
```

Finally, decode it, we got

```text
Hey guys! FLAG is SECCON{3n73r3d_fr0m_7h3_p3rf0rm4nc3_p4d_k3yb04rd}
```

