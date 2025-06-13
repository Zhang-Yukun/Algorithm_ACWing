def binpow(a: int, b: int, p: int) -> int:
    res = 1
    while b:
        if b & 1:
            res = res * a % p
        a = a * a % p
        b >>= 1
    return res

if __name__ == "__main__":
    n = int(input())
    MOD = 10 ** 9 + 7
    res = 1
    for i in range(1, n + 1):
        res = res * (2 * n - i + 1) % MOD * binpow(i, MOD - 2, MOD) % MOD
    res = res * binpow(n + 1, MOD - 2, MOD) % MOD
    print(res)
