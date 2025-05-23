# 第 k 个数

给定一个长度为 $n$ 的整数数列，以及一个整数 $k$，请用快速选择算法求出数列从小到大排序后的第 $k$ 个数。

## 输入格式

第一行包含两个整数 $n$ 和 $k$。

第二行包含 $n$ 个整数（所有整数均在 $1∼10^9$ 范围内），表示整数数列。

## 输出格式

输出一个整数，表示数列的第 $k$ 小数。

## 数据范围

$$1\le n\le 100000, \\
1\le k\le n$$

## 输入样例
```text
5 3
2 4 1 5 3
```

## 输出样例
```text
3
```

---

## Solution

第一种思路

```Cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, q[N];

int quick_sort(int q[], int l, int r, int k);

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%d", quick_sort(q, 0, n - 1, k));
}

int quick_sort(int q[], int l, int r, int k) {
    if (l >= r) return q[l];
    int i = l - 1, j = r + 1, p = q[l + ((r - l) >> 1)];
    while (i < j) {
        while (q[++i] < p);
        while (q[--j] > p);
        if (i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if (k <= sl) return quick_sort(q, l, j, k);
    else return quick_sort(q, j + 1, r, k - sl);
}
```

第二种思路
```Cpp
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
```
