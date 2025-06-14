def insert(d: list, x1: int, y1: int, x2: int, y2: int, c: int) -> None:
    d[x1][y1] += c
    d[x1][y2 + 1] -= c
    d[x2 + 1][y1] -= c
    d[x2 + 1][y2 + 1] += c

if __name__ == "__main__":
    n, m, q = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    d = [[0] * (m + 2) for _ in range(n + 2)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            insert(d, i, j, i, j, a[i - 1][j - 1])
    for _ in range(q):
        x1, y1, x2, y2, c = map(int, input().split())
        insert(d, x1, y1, x2, y2, c)
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1]
    for i in range(1, n + 1):
        print(" ".join(list(map(str, d[i][1:m + 1]))))
