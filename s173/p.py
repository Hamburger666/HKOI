

N, M = list(map(int, input().split()))

radars = list()
for radar in range(M):
    radars.append([
        cave - 1 for cave in
        list(map(int, input().split()))[1:]
    ])

if N == 1:
    print(0)
else:
    solved = [False] * N
    groupOfCaves = [0] * N
    solvedNo = 0
    groups = list()
    groups.append(set(range(N)))
    radar = 0
    while radar < M and solvedNo < N:
        changeList = dict()
        for cave in radars[radar]:
            if solved[cave]:
                continue
            oldGroup = groupOfCaves[cave]
            if oldGroup in changeList:
                newGroup = changeList[oldGroup]
            else:
                newGroup = len(groups)
                changeList[oldGroup] = newGroup
                groups.append(set())
            groups[oldGroup].remove(cave)
            groups[newGroup].add(cave)
            groupOfCaves[cave] = newGroup
        for oldGroup in changeList:
            newGroup = changeList[oldGroup]
            if len(groups[oldGroup]) == 1:
                solved[next(iter(groups[oldGroup]))] = True
                solvedNo += 1
            if len(groups[newGroup]) == 1:
                solved[next(iter(groups[newGroup]))] = True
                solvedNo += 1
        radar += 1
    if solvedNo == N:
        print(radar)
    else:
        print("Impossible")
