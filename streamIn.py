import subprocess

if __name__ == "__main__":
    st = "hi"
    p = subprocess.run(["./a.out"], stdout=subprocess.PIPE, input=st, encoding="ascii")
    print(p.stdout)