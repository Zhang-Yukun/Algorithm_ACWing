from collections import defaultdict

N = 10 ** 5 + 3

def find(h: dict, x: int) -> bool:
    t = ((x % N) + N) % N
    for item in h[t]:
        if item == x:
            return True
    return False

if __name__ == "__main__":
    n = int(input())
    h = defaultdict(list)
    for _ in range(n):
        op, x = input().split()
        x = int(x)
        if op == "I":
            h[((x % N) + N) % N].append(x)
        else:
            if find(h, x):
                print("Yes")
            else:
                print("No")
