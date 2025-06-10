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
    for _ in range(n):
        a, p = map(int, input().split())
        if a % p == 0:
            print("impossible")
        else:
            print(binpow(a, p - 2, p))
