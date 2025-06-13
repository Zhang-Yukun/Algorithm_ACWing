if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    res = 0
    for x in a:
        res += abs(x - a[n // 2])
    print(res)
