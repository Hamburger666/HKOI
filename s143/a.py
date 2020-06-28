N, L = map(int, input().split())
d = [input().strip() for i in range(N)]
ss = [dict() for _ in range(L)]
for i, word in enumerate(d):
    for j in range(L):
        ss[j][word[:j]+word[j+1:]] = i
W = int(input())
for _ in range(W):
    word = input().strip()
    for j in range(L):
        try:
            print(d[ss[j][word[:j]+word[j+1:]]])
            break;
        except KeyError:
            pass
