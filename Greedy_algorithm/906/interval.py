from heapq import heapify, heappush, heapreplace

if __name__ == "__main__":
    n = int(input())
    e = [tuple(map(int, input().split())) for _ in range(n)]
    e.sort(lambda x: x[0])
    h = []
    heapify(h)
    for l, r in e:
        if not h or l <= h[0]:
            heappush(h, r)
        else:
            heapreplace(h, r)
    print(len(h))
