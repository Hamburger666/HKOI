
def fib(n):
    if (l[n] == -1):
        x = fib(n-1) + fib(n-2)
        l[n] = x
        return x
    else:
        return l[n]

l = [-1] * 41
l[0] = 0
l[1] = 1
a = int(input())
print(fib(a))
