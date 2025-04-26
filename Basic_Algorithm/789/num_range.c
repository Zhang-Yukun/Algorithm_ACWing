#include <stdio.h>

#define N 100005

int n, q, k, l, r, a[N];

void binary_search_left();
void binary_search_right();

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        binary_search_left();
        binary_search_right();
        printf("%d %d\n", l, r);
    }
    return 0;
}

void binary_search_left() {
    int left = 0, right = n - 1, middle = left + ((right - left) >> 1);
    while (left <= right) {
        if (a[middle] == k) {
            if ((middle == 0) || (a[middle - 1] < k)) {
                l = middle;
                return;
            }
            right = middle - 1;
        } else if (a[middle] < k) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = left + ((right - left) >> 1);
    }
    l = -1;
}

void binary_search_right() {
    int left = 0, right = n - 1, middle = left + ((right - left) >> 1);
    while (left <= right) {
        if (a[middle] == k) {
            if ((middle == n - 1) || (a[middle + 1] > k)) {
                r = middle;
                return;
            }
            left = middle + 1;
        } else if (a[middle] < k) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = left + ((right - left) >> 1);
    }
    r = -1;
}