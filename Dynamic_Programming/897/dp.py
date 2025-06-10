if __name__ == "__main__":
    n, m = map(int, input().split())
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    a = input()
    b = input()
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            if a[i - 1] == b[j - 1]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
    print(dp[n][m])
