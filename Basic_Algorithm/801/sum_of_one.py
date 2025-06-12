if __name__ == "__main__":
    n = int(input())
    l = []
    for x in map(int, input().split()):
        res = 0
        while x:
            res += x & 1
            x >>= 1
        l.append(res)
    print(" ".join(list(map(str, l))))
