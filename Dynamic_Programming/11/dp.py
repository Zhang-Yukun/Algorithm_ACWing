if __name__ == "__main__":
    n, m = map(int, input().split())
    dp, cnt = [0] * (m + 1), [1] * (m + 1)
    cnt[0] = 1
    MOD = 10 ** 9 + 7
    for _ in range(n):
        v, w = map(int, input().split())
        for j in range(m, v - 1, -1):
            if dp[j - v] + w > dp[j]:
                dp[j] = dp[j - v] + w
                cnt[j] = cnt[j - v]
            elif dp[j - v] + w == dp[j]:
                cnt[j] += cnt[j - v]
    print(cnt[m] % MOD)
