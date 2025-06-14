if __name__ == "__main__":
    n = int(input())
    p = input()
    m = int(input())
    s = input()
    ne = [0] * n
    j = 0
    for i in range(1, n):
        while j and p[j] != p[i]:
            j = ne[j - 1]
        if p[j] == p[i]:
            j += 1
        ne[i] = j
    j = 0
    for i in range(m):
        while j and p[j] != s[i]:
            j = ne[j - 1]
        if p[j] == s[i]:
            j += 1
        if j == n:
            print(i - j + 1, end=" ")
            j = ne[j - 1]
