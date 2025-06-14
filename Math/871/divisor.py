from collections import defaultdict

if __name__ == "__main__":
    n = int(input())
    MOD = 10 ** 9 + 7
    primes = defaultdict(int)
    for _ in range(n):
        a = int(input())
        i = 2
        while i <= a // i:
            if a % i == 0:
                while a % i == 0:
                    primes[i] += 1
                    a //= i
            i += 1
        if a > 1:
            primes[a] += 1
    res = 1
    for prime, cnt in primes.items():
        t = 1
        for _ in range(cnt):
            t = (t * prime + 1) % MOD
        res = res * t % MOD
    print(res)
