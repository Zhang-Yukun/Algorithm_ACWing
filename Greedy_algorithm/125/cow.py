if __name__ == "__main__":
    n = int(input())
    e = [tuple(map(int, input().split())) for _ in range(n)]
    e.sort(lambda x: x[0] + x[1])
    res = -0x3f3f3f3f
    tw = 0
    for w, s in e:
        res = max(res, tw - s)
        tw += w
    print(res)
