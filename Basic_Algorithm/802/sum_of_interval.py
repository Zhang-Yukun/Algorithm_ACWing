def find(v: list, x: int) -> int:
    l, r = 0, len(v) - 1
    m = (l + r) >> 1
    while l <= r:
        if v[m] == x:
            return m + 1
        elif v[m] < x:
            l = m + 1
        else:
            r = m - 1
        m = (l + r) >> 1


if __name__ == "__main__":
    n, m = map(int, input().split())
    op, q, v = [], [], []
    for _ in range(n):
        x, c = map(int, input().split())
        op.append((x, c))
        v.append(x)
    for _ in range(m):
        l, r = map(int, input().split())
        q.append((l, r))
        v.append(l)
        v.append(r)
    v.sort()
    v = list(dict.fromkeys(v))
    s = [0] * (len(v) + 1)
    for x, c in op:
        s[find(v, x)] += c
    for i in range(1, len(s)):
        s[i] += s[i - 1]
    for l, r in q:
        print(s[find(v, r)] - s[find(v, l) - 1])
