if __name__ == "__main__":
    n = int(input())
    t = list(map(int, input().split()))
    t.sort()
    res = 0
    for i in range(1, n):
        res += t[i - 1] * (n - i)
    print(res)
