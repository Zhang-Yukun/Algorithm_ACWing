from collections import defaultdict

def dfs(u: int, g: dict, match: list, v: list) -> bool:
    for node in g[u]:
        if not v[node]:
            v[node] = True
            if match[node] == 0 or dfs(match[node], g, match, v):
                match[node] = u
                return True
    return False

if __name__ == "__main__":
    n1, n2, m  = map(int, input().split())
    g = defaultdict(list)
    match = [0] * (n2 + 1)
    res = 0
    for _ in range(m):
        x, y = map(int, input().split())
        g[x].append(y)
    for i in range(1, n1 + 1):
        v = [False] * (n2 + 1)
        if dfs(i, g, match, v):
            res += 1
    print(res)
