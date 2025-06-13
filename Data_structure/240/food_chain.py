def find(p: list, d: list, x: int) -> int:
    s = []
    while x != p[x]:
        s.append(x)
        x = p[x]
    root = x
    while s:
        x = s.pop()
        d[x] += d[p[x]]
        p[x] = p[p[x]]
    return root

if __name__ == "__main__":
    n, k = map(int, input().split())
    p = [i for i in range(n + 1)]
    d = [0] * (n + 1)
    res = 0
    for _ in range(k):
        q, x, y = map(int, input().split())
        if x > n or y > n:
            res += 1
        else:
            px, py = find(p, d, x), find(p, d, y)
            if q == 1:
                if px == py and (d[x] - d[y]) % 3 != 0:
                    res += 1
                elif px != py:
                    p[px] = py
                    d[px] = d[y] - d[x]
            else:
                if px == py and (d[x] - d[y] - 1) % 3 != 0:
                    res += 1
                elif px != py:
                    p[px] = py
                    d[px] = d[y] - d[x] + 1
    print(res)
