

# test is something with solution is said to have no solution

import subprocess

def add(a, b, m):
    sum = a+b
    sum = sum - sum//m*m
    return sum

def computeOut(a, b, m):
    one = add(a, b, m)
    two = add(2*a, b, m)
    three = add(3*a, b, m)
    return [one, two, three]

def checkout(out, one, two, three):
    a = out[0]
    b = out[1]
    m = out[2]
    answerShoud = computeOut(a, b, m)
    return (one == answerShoud[0] and two == answerShoud[1] and three==answerShoud[2])


def input(one, two, three):
    inputString = "%d %d %d" % (one, two, three)
    p = subprocess.run("./a.out", stdout=subprocess.PIPE, input = inputString.encode("utf-8"))
    outputString = p.stdout.decode("utf-8").strip()
    return outputString

def inject(a, b, m):
    out = computeOut(a, b, m)
    answer = input(out[0], out[1], out[2])
    if (answer == "No solution"):
        print("Wrong answer (No solution when there is) for: a=%d, b=%d, m=%d" % (a, b, m))
    else:
        results = [int(i) for i in answer.split(" ")]
        if not checkout(results, out[0], out[1], out[2]):
            print("Wrong answer for: a=%d, b=%d, m=%d" % (a, b, m))
            print("Given one=%d, two=%d, three=%d" % (out[0], out[1], out[2]))
            print("Came back a=%d, b=%d, m=%d" % (results[0], results[1], results[2]))




current = 0

for m in range(30):
    for a in range(m):
        for b in range(m):
            if (m != current):
                print(m)
                current = m
            inject(a, b ,m)


for sum in range(30):
    for one in range(sum):
        for two in range(sum - one):
            if (sum != current):
                print(sum)
                current = sum
            three = sum - one - two
            out = input(one, two, three)
            if out == "No solution":
                continue
            result = [int(i) for i in out.split(" ")]
            checkout(result, one, two, three)