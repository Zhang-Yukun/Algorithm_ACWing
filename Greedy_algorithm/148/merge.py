from heapq import heapify, heappop, heappush

if __name__ == "__main__":
    n = int(input())
    h = list(map(int, input().split()))
    heapify(h)
    res = 0
    while len(h) > 1:
        a, b = heappop(h), heappop(h)
        res += a + b
        heappush(h, a + b)
    print(res)
