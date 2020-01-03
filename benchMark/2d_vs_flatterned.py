import timeit

def way1():
    lineNo = int(input())
    begin = timeit.default_timer()
    c = []
    for line in range(lineNo):
        c.append(list(map(int, input().split()))[1:])
    end = timeit.default_timer()
    print(c[10][10])
    print(end - begin)

def way2():
    begin = timeit.default_timer()
    c = list()
    cMark = list()
    lineNo = int(input())
    for line in range(lineNo):
        cMark.append(len(c))
        c += list(map(int, input().split()))[1:]
    end = timeit.default_timer()
    print(end - begin)
    print(c[0])

if __name__ == "__main__":
    way2()

