from collections import defaultdict

if __name__ == "__main__":
    n = int(input())
    MOD = 10 ** 9 + 7
    p = defaultdict(int)
    for _ in range(n):
        x = int(input())
        i = 2
        while i <= x // i:
            if x % i == 0:
                while x % i == 0:
                    x //= i
                    p[i] += 1
            i += 1
        if x > 1:
            p[x] += 1
    res = 1
    for _, num in p.items():
        res = (res * (1 + num)) % MOD
    print(res)
