if __name__ == "__main__":
    n = int(input())
    a = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        a[i] += a[i - 1]
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for len in range(2, n + 1):
        for i in range(1, n + 1):
            j = i + len - 1
            if j > n:
                break
            dp[i][j] = 0x7f7f7f7f
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1])
    print(dp[1][n])
