def find(x: int, p: list) -> None:
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
    e = [tuple(map(int, input().split())) for _ in range(m)]
    e.sort(key=lambda x: x[2])
    res, cnt = 0, 0
    for x, y, z in e:
        px, py = find(x, p), find(y, p)
        if px != py:
            p[px] = py
            cnt += 1
            res += z
    if cnt < n - 1:
        print("impossible")
    else:
        print(res)
