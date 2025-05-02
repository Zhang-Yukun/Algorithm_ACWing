#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, q, k, a[N];

int binary_search_left(int a[], int l, int r, int k);
int binary_search_right(int a[], int l, int r, int k);

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  while (q--) {
    scanf("%d", &k);
    printf("%d %d\n", binary_search_left(a, 0, n - 1, k), binary_search_right(a, 0, n - 1, k));
  }
  return 0;
}

int binary_search_left(int a[], int l, int r, int k) {
  int m = (l + r) >> 1;
  while (l <= r) {
    if (a[m] == k) {
      if (m == 0 || a[m - 1] != k) return m;
      else r = m - 1;
    } else if (a[m] < k) {
      l = m + 1;
    } else {
      r = m - 1;
    }
    m = (l + r) >> 1;
  }
  return -1;
}

int binary_search_right(int a[], int l, int r, int k) {
  int m = (l + r) >> 1;
  while (l <= r) {
    if (a[m] == k) {
      if (m == n - 1 || a[m + 1] != k) return m;
      else l = m + 1;
    } else if (a[m] < k) {
      l = m + 1;
    } else {
      r = m - 1;
    }
    m = (l + r) >> 1;
  }
  return -1;
}
