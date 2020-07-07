import subprocess

for i in range(100):
    p = subprocess.run('./a.out', input=str(i).encode('ascii'), shell=True, capture_output=True)
    ns = list(map(int, p.stdout.decode('ascii').split()))
    aSum = 0
    bSum = 0
    for n in ns:
        if aSum <= bSum:
            aSum += n
        else:
            bSum += n
    print((aSum, bSum), aSum - bSum)

