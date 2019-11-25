import subprocess

a = 1
b = 2
c = 3
inputString = "%d %d %d" % (a, b, c)
print(inputString)
p = subprocess.run("./a.out", stdout=subprocess.PIPE, input=inputString.encode("utf-8"))
answer = p.stdout.decode("utf-8").strip()
result = [int(i) for i in answer.split(" ")]
print(result)