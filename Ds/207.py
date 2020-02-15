a, b = map(int, input().split())
gcd = 0
lcm = 0
i = max(a, b)
while(lcm == 0):
	if (i % a == 0 and i % b == 0): lcm = i
	i += 1
for i in range(max(a, b), 0, -1):
	if (a % i == 0 and b % i == 0): 
		gcd = i
		break

print(gcd)
print(lcm)