#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], n, q, k, res[2];

int binary_search_left(int left, int right, int k);
int binary_search_right(int left, int right, int k);


int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        res[0] = binary_search_left(0, n - 1, k);
        res[1] = binary_search_right(0, n - 1, k);
        printf("%d %d\n", res[0], res[1]);
    }
    return 0;
}

int binary_search_left(int left, int right, int k) {
    int l = left, r = right, m = l + ((r - l) >> 1);
    while (l <= r) {
        if  (a[m] == k) {
            if ((m == 0) || (a[m - 1] < k)) return m;
            r = m - 1;
        } else if (a[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        m = l + ((r - l) >> 1);
    }
    return -1;
}

int binary_search_right(int left, int right, int k) {
    int l = left, r = right, m = l + ((r - l) >> 1);
    while (l <= r) {
        if (a[m] == k) {
            if ((m == n - 1) || (a[m + 1] > k)) return m;
            l = m + 1;
        } else if (a[m] < k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        m = l + ((r - l) >> 1);
    }
    return -1;
}