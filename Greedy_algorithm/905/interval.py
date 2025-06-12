if __name__ == "__main__":
    n = int(input())
    intervals = []
    for _ in range(n):
        intervals.append(tuple(map(int, input().split())))
    intervals.sort(key=lambda x: x[1])
    r = -0x3f3f3f3f
    res = 0
    for interval in intervals:
        if interval[0] > r:
            r = interval[1]
            res += 1
    print(res)
