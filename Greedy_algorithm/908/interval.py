if __name__ == "__main__":
    n = int(input())
    intervals = []
    for _ in range(n):
        l, r = map(int, input().split())
        intervals.append((l, r))
    intervals.sort(key=lambda x: x[1])
    r = -0x7f7f7f7f
    res = 0
    for interval in intervals:
        if interval[0] > r:
            r = interval[1]
            res += 1
    print(res)
