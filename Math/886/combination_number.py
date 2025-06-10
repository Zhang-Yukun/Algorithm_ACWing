N, MOD = 10**5 + 1, 10**9 + 7
factor, ifactor = [1] * N, [1] * N

def binpow(a: int, b: int, p: int) -> int:
    res = 1
    while b:
        if b & 1:
            res = res * a % p
        a = a * a % p
        b >>= 1
    return res

if __name__ == "__main__":
    for i in range(1, N):
        factor[i] = factor[i - 1] * i % MOD
    ifactor[N - 1] = binpow(factor[N - 1], MOD - 2, MOD)
    for i in range(N - 2, 0, -1):
        ifactor[i] = ifactor[i + 1] * (i + 1) % MOD
    n = int(input())
    for _ in range(n):
        a, b = map(int, input().split())
        print(factor[a] * ifactor[a - b] % MOD * ifactor[b] % MOD)
