import random
s = set()
while len(s) != 5:
    s.add(random.randrange(10))
print(s)
sum=0
for x in s:
    sum+=x
print(sum/5)