from collections import deque

if __name__ == "__main__":
    n, m = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(n)]
    d = [[-1] * m for _ in range(n)]
    dx = (-1, 1, 0, 0)
    dy = (0, 0, -1, 1)
    d[0][0] = 0
    q = deque()
    q.append((0, 0))
    while q:
        i, j = q.popleft()
        for k in range(4):
            x, y = i + dx[k], j + dy[k]
            if x >= 0 and x < n and y >= 0 and y < m and g[x][y] == 0 and d[x][y] == -1:
                d[x][y] = d[i][j] + 1
                q.append((x, y))
    print(d[n - 1][m - 1])
