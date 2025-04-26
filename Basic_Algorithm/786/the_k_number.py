def quick_sort(q, left, right, k):
    if left >= right:
        return q[left]
    l, r = left, right
    p = q[l + ((r - l) >> 1)]
    while True:
        while q[l] < p:
            l += 1
        while q[r] > p:
            r -= 1
        if l >= r:
            break
        q[l], q[r] = q[r], q[l]
        l += 1
        r -= 1
    if k <= r - left + 1:
        return quick_sort(q, left, r, k)
    else:
        return quick_sort(q, r + 1, right, k - (r - left + 1))

def main():
    n, k = [int(x) for x in input().split()]
    q = [int(x) for x in input().split()]
    print(quick_sort(q, 0, n - 1, k))


main()
