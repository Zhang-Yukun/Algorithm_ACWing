// #include <stdio.h>

// #define N 100005

// int q[N], n, temp, k;

// int quick_sort(int left, int right, int k);

// int main() {
//     scanf("%d %d", &n, &k);
//     for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//     printf("%d", quick_sort(0, n - 1, k));
// }

// int quick_sort(int left, int right, int k) {
//     if (left >= right) return q[left];
//     int l = left, r = right, p = q[l + ((r - l) >> 1)];
//     while (1) {
//         while (q[l] < p) l++;
//         while (q[r] > p) r--;
//         if (l >= r) break;
//         temp = q[l];
//         q[l++] = q[r];
//         q[r--] = temp;
//     }
//     if (k <= r - left + 1) return quick_sort(left, r, k);
//     else return quick_sort(r + 1, right, k - r + left - 1);
// }

#include <stdio.h>

#define N 100005

int a[N], n, t, k, r;

int quick_sort(int a[], int left, int right, int k);

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    r = quick_sort(a, 0, n - 1, k);
    printf("%d", r);
    return 0;
}

int quick_sort(int a[], int left, int right, int k) {
    if (left >= right) return a[left];
    int l = left, r = right, p = a[l + ((r - l) >> 1)];
    while (1) {
        while (a[l] < p) l++;
        while (a[r] > p) r--;
        if (l >= r) break;
        t = a[l];
        a[l++] = a[r];
        a[r--] = t;
    }
    if (k <= (r - left + 1)) return quick_sort(a, left, r, k);
    else return quick_sort(a, r + 1, right, k - (r - left + 1));
}