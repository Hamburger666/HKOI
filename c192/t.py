import subprocess
import time

p = [False] * 2000000
for i in range(2, 2000000):
    if (not p[i]):
        for j in range(i*i, 2000000, i):
            p[j] = True

l = [1000]
for i in range(1000):
    l.append(i+800000)
start = time.time()
s = subprocess.run("./a.out", input=" ".join(map(str,l)), encoding="utf-8", capture_output=True)
out = list(map(int, s.stdout.split()))
e = time.time()-start
print("time", e)
for i in range(1000):
    if not (not p[out[i*2]] and not p[out[i*2+1]] and out[i*2] + out[i*2+1] == (i+800000) * 2) :
        print("failed")

print("success")
    