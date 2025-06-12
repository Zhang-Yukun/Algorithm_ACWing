if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for x in a:
        res ^= x
    if res:
        print("Yes")
    else:
        print("No")
