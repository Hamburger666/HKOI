from math import sqrt
a, b, c = map(int, input().split(" "))
try:
    x1 = (-b + sqrt((b**2) - (4 * a * c))) / (2 * a)
    x2 = (-b - sqrt((b**2) - (4 * a * c))) / (2 * a)
    if (x1 == x2) :
        print("%.3f" % x1)
    else:
        print("%.3f %.3f" % (min(x1, x2), max(x1, x2)))
except ValueError:
    print("None")