if __name__ == "__main__":
    n = int(input())
    q = [0] * (10 ** 5 + 10)
    h, t = 0, 0
    for _ in range(n):
        line = input().split()
        if line[0] == "push":
            q[t] = int(line[1])
            t += 1
        elif line[0] == "pop":
            h += 1
        elif line[0] == "empty":
            if h == t:
                print("YES")
            else:
                print("NO")
        else:
            print(q[h])
