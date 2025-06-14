if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * (10 ** 5 + 10)
    i, j = 0, 0
    res = 0
    while j < n:
        cnt[a[j]] += 1
        while cnt[a[j]] > 1:
            cnt[a[i]] -= 1
            i += 1
        res = max(res, j - i + 1)
        j += 1
    print(res)
