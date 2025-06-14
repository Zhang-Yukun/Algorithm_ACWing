# dp[i, r] = max(dp[i - 1, r])
# dp[i, r + v] = max(dp[i - 1, r + v], dp[i - 1, r] + w)
# ...
# dp[i, r + sv] = max(dp[i - 1, r + sv], dp[i - 1, r + (s - 1)v] + w, ..., dp[i - 1, r] + sw)
# dp[i, r + (s + 1)v] = max(dp[i - 1, r + (s + 1)v], dp[i - 1, r + sv] + w, ..., dp[i - r, r + v] + sw)
# ...
# dp[i, j - v] = max(dp[i - 1, j - v], dp[i - 1, j - 2v] + w, ..., dp[i - 1, j - sv] + (s - 1)w, dp[i - 1, j - (s + 1)v] + sw)
# dp[i, j] = max(dp[i - 1, j], dp[i - 1, j - v] + w, ..., dp[i - 1, j - sv] + sw)

from collections import deque

if __name__ == "__main__":
    n, m = map(int, input().split())
    dp = [[0] * (m + 1) for _ in range(2)]
    q = deque()
    for i in range(1, n + 1):
        v, w, s = map(int, input().split())
        for r in range(v):
            q.clear()
            for j in range(r, m + 1, v):
                while q and q[0] < j - s * v:
                    q.popleft()
                while q and dp[(i - 1) & 1][q[-1]] + (j - q[-1]) // v * w <= dp[(i - 1) & 1][j]:
                    q.pop()
                q.append(j)
                dp[i & 1][j] = dp[(i - 1) & 1][q[0]] + (j - q[0]) // v * w
    print(dp[n & 1][m])
