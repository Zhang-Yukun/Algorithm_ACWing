if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        l = []
        a = int(input())
        i = 1
        while i <= a // i:
            if a % i == 0:
                l.append(i)
                if i != a // i:
                    l.append(a // i)
            i += 1
        l.sort()
        print(" ".join(map(str, l)))
