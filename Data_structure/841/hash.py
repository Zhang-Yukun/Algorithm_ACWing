N, P = 2 ** 64, 131
def find_hash(l: int, r: int, h: list, p: list) -> int:
    return (h[r] - h[l - 1] * p[r - l + 1]) % N


if __name__ == "__main__":
    n, m = map(int, input().split())
    h, p = [0] * (n + 1), [1] * (n + 1)
    s = input()
    for i in range(len(s)):
        p[i + 1] = p[i] * P % N
        h[i + 1] = (h[i] * P + ord(s[i]) - ord('0') + 1) % N
    for _ in range(m):
        l1, r1, l2, r2 = map(int, input().split())
        if (find_hash(l1, r1, h, p) == find_hash(l2, r2, h, p)):
            print("Yes")
        else:
            print("No")
