#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, q[N], t[N];

void merge_sort(int a[], int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1, i = l, j = m + 1, k = 0;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = t[k];
}
