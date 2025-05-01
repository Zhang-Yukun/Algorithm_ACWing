#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, q[N];

void quick_sort(int a[], int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}

void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, pivot = a[(i + j) >> 1];
    while (true) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) break;
        swap(a[i++], a[j--]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
