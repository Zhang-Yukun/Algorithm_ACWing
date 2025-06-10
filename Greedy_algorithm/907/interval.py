if __name__ == "__main__":
    s, t = map(int, input().split())
    n = int(input())
    e = []
    for _ in range(n):
        e.append(tuple(map(int, input().split())))
    e.sort()
    res = 0
    i = j = 0
    while i < n:
        r = -0x3f3f3f3f
        while j < n and e[j][0] <= s:
            r = max(r, e[j][1])
            j += 1
        res += 1
        if r < s or r >= t:
            break
        s = r
        i = j
    if r < t:
        res = -1
    print(res)
