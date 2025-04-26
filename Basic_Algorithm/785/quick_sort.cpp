#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, q[N];

void quick_sort(int q[], int l, int r);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
}

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r, p = q[l + ((r - l) >> 1)];
    while (true) {
        while (q[i] < p) i++;
        while (q[j] > p) j--;
        if (i >= j) break;
        swap(q[i++], q[j--]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}