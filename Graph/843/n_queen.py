def dfs(r: int, n: int, g: list, col: list, diag: list, udiag: list):
    if r == n:
        for i in range(n):
            print("".join(g[i]))
        print()
        return
    for c in range(n):
        if not col[c] and not diag[r + c] and not udiag[n - r + c - 1]:
            col[c] = diag[r + c] = udiag[n - r + c - 1] = True
            g[r][c] = "Q"
            dfs(r + 1, n, g, col, diag, udiag)
            g[r][c] = "."
            col[c] = diag[r + c] = udiag[n - r + c - 1] = False

if __name__ == "__main__":
    n = int(input())
    g = [["."] * n for _ in range(n)]
    col, diag, udiag = [False] * n, [False] * (2 * n), [False] * (2 * n)
    dfs(0, n, g, col, diag, udiag)
