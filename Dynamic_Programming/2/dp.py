if __name__ == "__main__":
    n, m = map(int, input().split())
    dp = [0] * (m + 1)
    for _ in range(n):
        v, w = map(int, input().split())
        for j in range(m, v - 1, -1):
            dp[j] = max(dp[j], dp[j - v] + w)
    print(dp[m])
