#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, pos, len, a[N], q[N];


int binary_search_left(int a[], int l, int r, int k);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    q[0] = -2e9;
    for (int i = 1; i <= n; i++) {
        pos = binary_search_left(q, 0, len, a[i]);
        len = max(len, pos + 1);
        q[pos + 1] = a[i];
    }
    printf("%d", len);
    return 0;
}

int binary_search_left(int a[], int l, int r, int k) {
    int m = (l + r) >> 1, len = r;
    while (l <= r) {
        if (a[m] < k) {
            if (m == len || a[m + 1] >= k) return m;
            else l = m + 1;
        } else if (a[m] >= k) r = m - 1;
        m = (l + r) >> 1;
    }
    return 0;
}