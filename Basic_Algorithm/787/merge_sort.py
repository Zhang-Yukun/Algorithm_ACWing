def merge_sort(l: int, r: int, a: int) -> None:
    if l >= r:
        return
    m = (l + r) >> 1
    merge_sort(l, m, a)
    merge_sort(m + 1, r, a)
    i, j = l, m + 1
    t = []
    while i <= m and j <= r:
        if a[i] <= a[j]:
            t.append(a[i])
            i += 1
        else:
            t.append(a[j])
            j += 1
    while i <= m:
        t.append(a[i])
        i += 1
    while j <= r:
        t.append(a[j])
        j += 1
    a[l: r + 1] = t[:]
    

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    merge_sort(0, n - 1, a)
    print(" ".join(map(str, a)))
