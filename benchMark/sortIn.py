import random
file = open("sortIn.txt", "w")
for i in range(100000):
    n = random.randrange(0, 10**9)
    file.write(str(n))
    file.write(" ")
file.close()