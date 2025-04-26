#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, q[N];

int quick_sort(int q[], int l, int r, int k);

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%d", quick_sort(q, 0, n - 1, k - 1));
}

int quick_sort(int q[], int l, int r, int k) {
    if (l >= r) return q[k];
    int i = l - 1, j = r + 1, p = q[l + ((r - l) >> 1)];
    while (i < j) {
        while (q[++i] < p);
        while (q[--j] > p);
        if (i < j) swap(q[i], q[j]);
    }
    if (k <= j) return quick_sort(q, l, j, k);
    else return quick_sort(q, j + 1, r, k);
}