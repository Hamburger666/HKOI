one = list(map(int, input().split(" ")))
two = list(map(int, input().split(" ")))

winner = 0
for i in range(3):
    if (one[i] > two[i]):
        winner = 1
        break;
    elif (one[i] < two[i]):
        winner = 2
        break

if winner == 0:
    print("Same")
elif winner == 1:
    print("After")
elif winner == 2:
    print("Before")
