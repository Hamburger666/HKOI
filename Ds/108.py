l = list(input().split(" "))
rtl = (l[3] != "*")
result = 0
l.insert(0, "+")
l.append("+")
if (not rtl):
    l.reverse()

for i in range(3):
    op = l[2*i]
    n = int(l[2*i+1])
    if (op == "+"):
        result += n
    elif (op == "-"):
        if (not rtl):
            result = -result
            result += n
        else:
            result -= n
    elif (op == "*"):
        result *= n
print(result)