import math
n, d = map(int, input().split())

gdc = math.gcd(n, d)
n //= gdc
d //= gdc

if (n % d == 0):
	print(n//d)
else:
	intPart = n//d
	n %= d
	s2 = 0
	s5 = 0
	dt = d

	while(dt % 2==0):
		s2 += 1
		dt //= 2
	while(dt %5 ==0) :
		s5 += 1
		dt //=5
	s10 = max(s2, s5)
	for i in range(s2, s5):
		n *= 2
	for i in range(s5, s2):
		n *= 5

	if (dt == 1):
		print(intPart + n/10** s10)
	else:
		while(n % 10 == 0 and s10 > 0):
			n //= 10
			s10 -= 1
		alone = n // dt
		n %= dt
		l = 9
		i = 1
		while(l % dt != 0):
			l += 9 * 10 ** i
			i += 1
		n = n * (l // dt)
		if n == 0:
			print("%0.*f" % (s10, intPart+alone/10**s10))
		elif alone == 0 and s10 == 0:
			print(str(intPart) + (".[" + str(n).zfill(i) + "]"))
		else:
			print("%0.*f" % (s10, intPart+alone/10**s10) + ("[" + str(n).zfill(i) + "]"))
