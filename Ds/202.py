from math import sqrt
a = int(input())
s = []
x = []
r = int(sqrt(a))
for i in range(r):
    k = i+1
    if (a % k == 0):
        s.append(k)
        if (k != a // k):
            x.append(a // k)
for i in range(len(s)):
    print(s[i])

for i in reversed(range(len(x))):
    print(x[i])



