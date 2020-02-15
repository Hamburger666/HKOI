a = int(input())
l = [a//2 * " " + "#"]
for i in range(1, a//2):
	l.append((a//2 - i) * " " + "#" + (i * 2 - 1) * " " + "#")

if a == 1:
	print("#")
else:
	for i in range(a//2):
		print(l[i])
	print("#" + " " * (a-2) + "#")
	for i in reversed(range(a//2)):
		print(l[i])


