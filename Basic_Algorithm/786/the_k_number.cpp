#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, q[N];

int quick_sort(int a[], int l, int r, int k);

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%d", quick_sort(q, 0, n - 1, k));
    return 0;
}

int quick_sort(int a[], int l, int r, int k) {
    if (l >= r) return a[l];
    int i = l, j = r, pivot = a[(i + j) >> 1];
    while (true) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;
        swap(a[i++], a[j--]);
    }
    if (k <= j - l + 1) return quick_sort(a, l, j, k);
    else return quick_sort(a, j + 1, r, k - j + l - 1);
}
