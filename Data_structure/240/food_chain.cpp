#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, q, x, y, res, px, py, p[N], d[N];

int find(int x);

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) p[i] = i;
    while (k--) {
        scanf("%d%d%d", &q, &x, &y);
        if (x > n || y > n) res++;
        else {
            px = find(x), py = find(y);
            if (q == 1) {
                if (px == py && (d[x] - d[y]) % 3) res++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            } else {
                if (px == py && (d[x] - d[y] - 1) % 3) res++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}