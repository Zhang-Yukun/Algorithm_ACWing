N = int(1e5 + 10)
h, idx = 0, 2
e, l, r = [0] * N, [0] * N, [0] * N
r[0], l[1] = 1, 0

def ilh(x: int):
    global idx
    e[idx] = x
    l[idx] = 0
    r[idx] = r[0]
    l[r[0]] = idx
    r[0] = idx
    idx += 1

def irh(x: int):
    global idx
    e[idx] = x
    r[idx] = 1
    l[idx] = l[1]
    r[l[1]] = idx
    l[1] = idx
    idx += 1

def il(k: int, x: int):
    global idx
    e[idx] = x
    r[idx] = k
    l[idx] = l[k]
    r[l[k]] = idx
    l[k] = idx
    idx += 1

def ir(k: int, x: int):
    global idx
    e[idx] = x
    l[idx] = k
    r[idx] = r[k]
    l[r[k]] = idx
    r[k] = idx
    idx += 1
    
def rm(k: int):
    r[l[k]] = r[k]
    l[r[k]] = l[k]
    


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        line = input().split()
        if line[0] == "L":
            x = int(line[1])
            ilh(x)
        elif line[0] == "R":
            x = int(line[1])
            irh(x)
        elif line[0] == "IL":
            k, x = int(line[1]), int(line[2])
            il(k + 1, x)
        elif line[0] == "IR":
            k, x = int(line[1]), int(line[2])
            ir(k + 1, x)
        else:
            k = int(line[1])
            rm(k + 1)
    i = r[0]
    line = []
    while i != 1:
        line.append(str(e[i]))
        i = r[i]
    print(" ".join(line))
