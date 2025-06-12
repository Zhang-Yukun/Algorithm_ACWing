from collections import defaultdict

def topsort(g: dict, in_degrees: list) -> None:
    q = []
    for i in range(1, len(in_degrees)):
        if in_degrees[i] == 0:
            q.append(i)
    i = 0
    while i < len(q):
        node = q[i]
        for neighbor in g[node]:
            in_degrees[neighbor] -= 1
            if in_degrees[neighbor] == 0:
                q.append(neighbor)
        i += 1
    if len(q) == len(in_degrees) - 1:
        print(" ".join(list(map(str,q))))
    else:
        print("-1")

if __name__ == "__main__":
    g = defaultdict(list)
    n, m = map(int, input().split())
    in_degrees = [0] * (n + 1)
    for _ in range(m):
        x, y = map(int, input().split())
        g[x].append(y)
        in_degrees[y] += 1
    topsort(g, in_degrees)
    