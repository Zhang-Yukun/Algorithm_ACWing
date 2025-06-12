def find(x: int, p: list) -> int:
    root = x
    while root != p[root]:
        root = p[root]
    while x != p[x]:
        t = p[x]
        p[x] = root
        x = t
    return root

if __name__ == "__main__":
    n, m = map(int, input().split())
    p = [i for i in range(n + 1)]
    cnt = [1] * (n + 1)
    for _ in range(m):
        line = input().split()
        op = line[0]
        if op == "C":
            x, y = int(line[1]), int(line[2])
            px, py = find(x, p), find(y, p)
            if px != py:
                p[px] = py
                cnt[py] += cnt[px]
        elif op == "Q1":
            x, y = int(line[1]), int(line[2])
            px, py = find(x, p), find(y, p)
            if px == py:
                print("Yes")
            else:
                print("No")
        else:
            x = int(line[1])
            print(cnt[find(x, p)])
