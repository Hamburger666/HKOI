def sum(x, y):
    return b[y] - b[x]

N, K = map(int, input().split())
A = list(map(int, input().split()))

A = [x * 2 for x in A]
A.sort()
b =[0] * (N+1)
for i in range(N):
    b[i + 1] = b[i] + A[i]

if K == 1 or K == 2:
    print(*[A[i] // 2 for i in range(K)])
else: 
    if K % 2 == 0:
        pass
    else:
        maxv = - 10**11
        maxi = 0
        for i in range(K//2 + 1, N - K//2):
            v = A[i] * K - K - sum(0, K//2) - sum(i + 1, i + 1 + K//2)
            if v > maxv:
                maxv = v
                maxi = i

        l =[]
        for i in range(K//2):
            l.append(A[i]//2)
        
        for i in range(maxi, maxi + 1 + K//2):
            l.append(A[i]//2)

        print(*l)

