def quick_sort(data, left, right):
    if left >= right:
        return
    l, r = left, right
    p = data[l + ((r - l) >> 1)]
    while True:
        while data[l] < p:
            l += 1
        while data[r] > p:
            r -= 1
        if l >= r:
            break
        data[l], data[r] = data[r], data[l]
        l += 1
        r -= 1
    quick_sort(data, left, r)
    quick_sort(data, r + 1, right)


def main():
    n = int(input())
    data = [int(x) for x in input().split()]
    quick_sort(data, 0, n - 1)
    print(" ".join(list(map(str, data))))


main()
