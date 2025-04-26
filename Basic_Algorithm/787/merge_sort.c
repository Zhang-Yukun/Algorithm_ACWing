// #include <stdio.h>

// #define N 100005

// int q[N], t[N], n;

// void merge_sort(int left, int right);

// int main() {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//     merge_sort(0, n - 1);
//     for (int i = 0; i < n; i++) printf("%d ", q[i]);
//     return 0;
// }

// void merge_sort(int left, int right) {
//     if (left >= right) return;
//     int m = left + ((right - left) >> 1);
//     merge_sort(left, m);
//     merge_sort(m + 1, right);
//     int i = left, j = m + 1, k = 0;
//     while ((i <= m) && (j <= right)) {
//         if (q[i] <= q[j]) t[k++] = q[i++];
//         else t[k++] = q[j++];
//     }
//     while (i <= m) t[k++] = q[i++];
//     while (j <= right) t[k++] = q[j++];
//     for (i = left, k = 0; i <= right; i++, k++) q[i] = t[k];
// }

#include <stdio.h>

#define N 100005

int a[N], t[N], n;

void merge_sort(int a[], int left, int right);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

void merge_sort(int a[], int left, int right) {
    if (left >= right) return;
    int m = left + ((right - left) >> 1);
    merge_sort(a, left, m);
    merge_sort(a, m + 1, right);
    int i = left, j = m + 1, k = 0;
    while ((i <= m) && (j <= right)) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= right) t[k++] = a[j++];
    for (i = left, k = 0; i <= left; i++, k++) a[i] = t[k];
}