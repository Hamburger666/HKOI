from math import sqrt, floor
a = int(input())
r = sqrt(a)
r2 = sqrt(2 * a)
isS = (int(r) ** 2 == a)
isT = (floor(r2) * (floor(r2) + 1) == a * 2)
if (isS and isT):
    print("Both")
elif (isS):
    print("Square")
elif (isT):
    print("Triangular")
else:
    print("Neither")


