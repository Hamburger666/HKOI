a = int(input())
notes = [1000, 500, 100, 50, 20, 10]
onNote = 0
remain = a
while(remain > 0):
    while(remain >= notes[onNote]):
        print(notes[onNote])
        remain -= notes[onNote]
    onNote += 1

