import random
if __name__ == "__main__":
    fileString = ""
    file = open("2vf.txt", "w")
    bound = 10**6
    index = 0
    lineNo = 0
    while (index < bound):
        lineNo += 1
        ran = random.randint(1, 1000)
        if (index + ran < bound):
            index += ran
        else:
            ran = bound - index
            index = bound
        fileString += str(ran)
        fileString += " "
        for j in range(ran):
            number = random.randint(0, 100)
            fileString += str(number)
            fileString += " "
        fileString += "\n"
    file.write(str(lineNo) + "\n")
    file.write(fileString)
    file.close()