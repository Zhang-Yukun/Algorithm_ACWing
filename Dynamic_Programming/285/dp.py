from collections import defaultdict

def bfs(root: int, g: dict, h: list, dp: list) -> None:
    q = []
    q.append(root)
    i = 0
    while i < len(q):
        u = q[i]
        for node in g[u]:
            q.append(node)
        i += 1
    while q:
        u = q.pop()
        dp[1][u] = h[u]
        for node in g[u]:
            dp[1][u] += dp[0][node]
            dp[0][u] += max(dp[0][node], dp[1][node])
if __name__ == "__main__":
    n = int(input())
    h = [0] + [int(input()) for _ in range(n)]
    dp = [[0] * (n + 1) for _ in range(2)]
    g = defaultdict(list)
    v = [False] * (n + 1)
    for i in range(1, n):
        x, y = map(int, input().split())
        g[y].append(x)
        v[x] = True
    root = 1;
    while v[root]:
        root += 1
    bfs(root, g, h, dp)
    print(max(dp[0][root], dp[1][root]))
