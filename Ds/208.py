n = int(input())
l = list(map(int, input().split()))

maxv = -2147483649
maxi1 = 0
for i, v in enumerate(l):
	if v > maxv:
		maxv = v
		maxi1 = i

maxv = -2147483649
maxi2 = 0
for i, v in enumerate(l):
	if i != maxi1:
		if v > maxv:
			maxv = v
			maxi2 = i

print(l[maxi1], l[maxi2], sep = '\n')