from math import sin, pi
a = int(input())
b = int(input())
C = int(input())
ans = a * b * sin(pi/180 * C) / 2
print("%.3f" % ans)