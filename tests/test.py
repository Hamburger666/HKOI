n = input()
x = ''
y = '____________________'
x = y[:len(n)]
while x != n:
	c = input()
	x = list(x)
	for i in range(len(n)):
		if c == n[i]:
			x[i] = n[i]
	x = ''.join(x)
	print(x)