// #include <stdio.h>

// #define N 100005

// int a[N], t[N], n;
// long long res;

// void merge_sort(int l, int r);

// int main() {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//     merge_sort(0, n - 1);
//     printf("%lld", res);
//     return 0;
// }

// void merge_sort(int l, int r) {
//     if (l >= r) return;
//     int m = l + ((r - l) >> 1), i = l, j = m + 1, k = 0;
//     merge_sort(l, m);
//     merge_sort(m + 1, r);
//     while ((i <= m) && (j <= r)) {
//         if (a[i] <= a[j]) t[k++] = a[i++];
//         else {
//             res += (m  - i + 1);
//             t[k++] = a[j++];
//         }
//     }
//     while (i <= m) t[k++] = a[i++];
//     while (j <= r) t[k++] = a[j++];
//     k = 0;
//     for (i = l; i <= r; i++) a[i] = t[k++];
// }


#include <stdio.h>

#define N 100005

int a[N], t[N], n;
long long res;

void merge_sort(int a[], int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    printf("%lld", res);
    return 0;
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int m = l + ((r - l) >> 1);
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    int i = l, j = m + 1, k = 0;
    while ((i <= m) && (j <= r)) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else {
            res += (m - i + 1);
            t[k++] = a[j++];
        }
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = t[k];
}