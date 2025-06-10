def find(x: int, p: list) -> int:
    root = x
    while p[root] != root:
        root = p[root]
    while p[x] != x:
        t = p[x]
        p[x] = root
        x = p[t]
    return root
    
if __name__ == "__main__":
    n, m = map(int, input().split())
    p = [i for i in range(n + 1)]
    for _ in range(m):
        line = input().split()
        op, x, y = line[0], int(line[1]), int(line[2])
        px, py = find(x, p), find(y, p)
        if op == "M":
            if px != py:
                p[px] = py
        else:
            if px == py:
                print("Yes")
            else:
                print("No")
