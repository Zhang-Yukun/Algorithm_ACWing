if __name__ == "__main__":
    n = int(input())
    intervals = [None] * n
    for i in range(n):
        interval = tuple(map(int, input().split()))
        intervals[i] = interval
    intervals.sort()
    r = intervals[0][1]
    res = 1
    for i in range(1, n):
        if intervals[i][0] <= r:
            r = max(r, intervals[i][1])
        else:
            r = intervals[i][1]
            res += 1
    print(res)
