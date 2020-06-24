import copy
import subprocess
import progressbar
def fill(g, x, y, X, Y, c, bar):
    if x == X and y == Y:
        if getFromA(toS(g)) != getFromB(toS(g)):
            print(g)
        c += 1
        try:
            bar.update(c)
        except:
            pass
        return c
    gc = copy.deepcopy(g)
    gc[x][y] = True
    x += 1
    if (x > X):
        x = 0
        y += 1
    c = fill(g, x, y, X, Y, c, bar)
    c = fill(gc, x, y, X, Y, c, bar)
    return c

def toS(g):
    lines = []
    k = 0
    for x in range(len(g)):
        for y in range(len(g[x])):
            if g[x][y]:
                lines.append('%d %d' % (x, y))
                k += 1
    return '%d %d %d\n' % (len(g)-1, len(g[0]) - 1, k) + '\n'.join(lines)

def getFromA(s):
    p = subprocess.run('./a.out', input=s.encode('utf-8'), capture_output=True)
    return(p.stdout.decode('utf-8').strip())

def getFromB(s):
    p = subprocess.run('./b.out', input=s.encode('utf-8'), capture_output=True)
    return(p.stdout.decode('utf-8').strip())

with progressbar.ProgressBar(max_value = 2**(11 * 11)) as bar:
    fill([[False] * 11] * 11, 0, 0, 10, 10, 0, bar)
