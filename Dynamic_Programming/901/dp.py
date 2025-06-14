def dfs(x: int, y: int, h: list, dp: list) -> int:
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 1
    dx = (-1, 1, 0, 0)
    dy = (0, 0, -1, 1)
    for i in range(4):
        u, v = x + dx[i], y + dy[i]
        if u >= 0 and u < len(h) and v >= 0 and v < len(h[0]) and h[u][v] < h[x][y]:
            dp[x][y] = max(dp[x][y], dfs(u, v, h, dp) + 1)
    return dp[x][y]

if __name__ == "__main__":
    n, m = map(int, input().split())
    h = [list(map(int, input().split())) for _ in range(n)]
    dp = [[-1] * m for _ in range(n)]
    res = 0
    for i in range(n):
        for j in range(m):
            res = max(res, dfs(i, j, h, dp))
    print(res)
