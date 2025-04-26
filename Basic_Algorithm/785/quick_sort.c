// #include <stdio.h>

// #define N 100005

// int n, q[N], temp;

// void quick_sort(int left, int right);

// int main() {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//     quick_sort(0, n - 1);
//     for (int i = 0; i < n; i++) printf("%d ", q[i]);
// }

// void quick_sort(int left, int right) {
//     if (left >= right) return;
//     int l = left, r = right, pivot = q[l + ((r - l) >> 1)];
//     while (1) {
//         while (q[l] < pivot) l++;
//         while (q[r] > pivot) r--;
//         if (l >= r) break;
//         temp = q[l];
//         q[l++] = q[r];
//         q[r--] = temp;
//     }
//     quick_sort(left, r);
//     quick_sort(r + 1, right);
// }

#include <stdio.h>

#define N 100005

int a[N], n, t;

void quick_sort(int a[], int left, int right);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

void quick_sort(int a[], int left, int right) {
    if (left >= right) return;
    int l = left, r = right, p = a[l + ((r - l) >> 1)];
    while (1) {
        while (a[l] < p) l++;
        while (a[r] > p) r--;
        if (l >= r) break;
        t = a[l];
        a[l++] = a[r];
        a[r--] = t;
    }
    quick_sort(a, left, r);
    quick_sort(a, r + 1, right);
}