if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        x = int(input())
        i = 2
        cnt = 0
        while i <= x // i:
            if x % i == 0:
                cnt = 0
                while x % i == 0:
                    cnt += 1
                    x //= i
                print(f"{i} {cnt}")
            i += 1
        if x > 1:
            print(f"{x} 1")
        print()
