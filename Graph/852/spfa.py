from collections import deque, defaultdict

def spfa(g: dict, d: list, cnt: list, v: list) -> bool:
    q = deque()
    for i in range(1, len(v)):
        q.append(i)
        v[i] = True
    while q:
        node = q.popleft()
        v[node] = False
        for (neighbor, distance) in g[node]:
            if d[neighbor] > d[node] + distance:
                d[neighbor] = d[node] + distance
                cnt[neighbor] = cnt[node] + 1
                if cnt[neighbor] == n:
                    return True
                if v[neighbor] == False:
                    q.append(neighbor)
                    v[neighbor] = True
    return False

if __name__ == "__main__":
    n, m = map(int, input().split())
    g = defaultdict(list)
    d = [0] * (n + 1)
    cnt = [0] * (n + 1)
    v = [False] * (n + 1)
    for _ in range(m):
        x, y, z = map(int, input().split())
        g[x].append((y, z))
    if spfa(g, d, cnt, v):
        print("Yes")
    else:
        print("No")
