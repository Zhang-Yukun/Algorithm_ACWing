from collections import defaultdict, deque

def bfs(u: int, c: int, g: dict, color: list) -> bool:
    q = deque()
    color[u] = c
    q.append((u, c))
    while q:
        u, c = q.popleft()
        for i in g[u]:
            if not color[i]:
                color[i] = 3 - c
                q.append((i, color[i]))
            elif color[i] == c:
                return False
    return True

if __name__ == "__main__":
    n, m = map(int, input().split())
    g = defaultdict(list)
    color = [0] * (n + 1)
    for _ in range(m):
        x, y = map(int, input().split())
        g[x].append(y)
        g[y].append(x)
    flag = True
    for i in range(1, n + 1):
        if not color[i] and not bfs(i, 1, g, color):
            flag = False
            break
    if flag:
        print("Yes")
    else:
        print("No")
