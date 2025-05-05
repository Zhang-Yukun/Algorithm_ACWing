#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, res, idx, a[N], t[32 * N][2];

void insert(int x);
int query(int x);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        res = max(res, query(a[i]));
    }
    printf("%d", res);
    return 0;
}

void insert(int x) {
    int loc = 0, val = 0;
    for (int i = 31; i >= 0; i--) {
        val = (x >> i) & 1;
        if (!t[loc][val]) t[loc][val] = ++idx;
        loc = t[loc][val];
    }
}

int query(int x) {
    int loc = 0, val = 0, res = 0;
    for (int i = 31; i >= 0; i--) {
        val = (x >> i) & 1;
        res <<= 1;
        if (t[loc][!val]) {
            res++;
            loc = t[loc][!val];
        } else {
            loc = t[loc][val];
        }
    }
    return res;
}