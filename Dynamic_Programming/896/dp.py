if __name__ == "__main__":
    n = int(input())
    l = list(map(int, input().split()))
    s = []
    for x in l:
        if not s or x > s[-1]:
            s.append(x)
        else:
            l = 0
            r = len(s) - 1
            m = (l + r) >> 1
            while l <= r:
                if s[m] < x:
                    if m == len(s) - 1 or s[m + 1] >= x:
                        break
                    else:
                        l = m + 1
                elif s[m] >= x:
                    r = m - 1
                m = (l + r) >> 1
            s[m + 1] = x
    print(len(s))
