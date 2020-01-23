# Codegate CTF 2019 Preliminary

## Programming - Algo\_Auth

Task is quite trivial

![](.gitbook/assets/image%20%2862%29.png)

It turns out this challenge is project euler 82 :\)

{% code title="solver.py" %}
```python
import os
import heapq
from pwn import *
import base64
def parse_matrix(s):
	s = s.replace('\n', '').split(' ')
	tmp = []
	for i in range(0, len(s)):
		if s[i] != ' ' and s[i] != '\n' and s[i] != '':
			tmp.append(s[i])

	arr = []
	for i in range(0, len(tmp), 7):
		arr.append([int(tmp[i]), int(tmp[i+1]), int(tmp[i+2]), int(tmp[i+3]), int(tmp[i+4]), int(tmp[i+5]), int(tmp[i+6])])
	return arr

def distance(a, b):
    return sum(abs(a[i] - b[i]) for i in range(len(a)))

def astar(matrix, targets, sources):
    def neighbors(position):
        (x, y) = position
        candidates = [(x, y - 1), (x, y + 1), (x + 1, y)]
        return [(x, y) for (x, y) in candidates if x >= 0 and x < len(matrix)
                                               and y >= 0 and y < len(matrix[0])]

    def evaluate(path):
        f = sum(matrix[y][x] for (x, y) in path)
        h = min(distance(path[-1], target) for target in targets)
        return f + h

    targets = set(targets)
    frontier = set(sources)
    explored = set()
    frontier_queue = []
    for source in sources:
        path = [source]
        heapq.heappush(frontier_queue, (evaluate(path), path))

    while frontier:
        (_, path) = heapq.heappop(frontier_queue)
        frontier.remove(path[-1])
        explored.add(path[-1])
        if path[-1] in targets:
            return path
        for neighbor in neighbors(path[-1]):
            if neighbor not in frontier | explored:
                frontier.add(neighbor)
                new_path = path + [neighbor]
                heapq.heappush(frontier_queue, (evaluate(new_path), new_path))

def main():
    count = 1
    output_flag = ""
    r = remote('110.10.147.109', 15712)
    print r.recv()
    r.send('G\n')
    while count <= 100:
     s = r.recv().strip().split('\n')
     print s
     s = s[1:]
     s = s[:-2]
     s = '\n'.join(s)
     print s
     matrix = parse_matrix(s)
     targets = [(len(row) - 1, y) for y, row in enumerate(matrix)]
     sources = [(0, y) for y, row in enumerate(matrix)]
     out = (sum(matrix[y][x] for (x, y) in astar(matrix, targets, sources)))
     if count == 45:
      out = 100
     print out
     output_flag += chr(out)
     r.send(str(out) + '\n')
     count += 1
    print output_flag
    print base64.b64decode(output_flag)
if __name__ == "__main__": main()
```
{% endcode %}

The task is quite trivial, after done all stage, you just need to convert all your answers to chr\(\) and decode base64.

![pof.png](.gitbook/assets/image%20%28147%29.png)

