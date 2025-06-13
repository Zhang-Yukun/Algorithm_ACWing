def insert(l: int, r: int, c: int, d: list) -> None:
    d[l] += c
    d[r + 1] -= c

if __name__ == "__main__":
    n, m = map(int, input().split())
    d = [0] * (n + 2)
    for idx, x in enumerate(list(map(int, input().split()))):
        insert(idx + 1, idx + 1, x, d)
    for _ in range(m):
        l, r, c = map(int, input().split())
        insert(l, r, c, d)
    for i in range(1, n + 1):
        d[i] += d[i - 1]
    print(" ".join(map(str, d[1: n + 1])))
