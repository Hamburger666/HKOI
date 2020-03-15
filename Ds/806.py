def r(left, right):
    mid = (left+right)//2
    r(left, mid)
    r(mid, right)
    print(left+1, mid, mid+1, right)
N = int(input())
r(0, N)