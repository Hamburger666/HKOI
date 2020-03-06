s = input()
t = input()
lastsubstringends = 0
subC = 0
nonC = 0
for i in range(len(s) - len(t) + 1):
    if s[i:i+len(t)] == t:
        if i >= lastsubstringends:
            lastsubstringends = i+len(t)
            nonC += 1
        subC += 1
print(subC)
print(nonC)


