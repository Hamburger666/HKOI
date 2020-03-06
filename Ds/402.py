n = int(input())
p = dict()
for i in range(n):
    barcode, price = input().split()
    price = float(price)
    p[barcode] = price
m = int(input())
total = 0
for i in range(m):
    barcode = input()
    total += p[barcode]
print("%.1f" % total)