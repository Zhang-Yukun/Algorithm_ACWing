#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, h[N];

void down(int u);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = n / 2; i; i--) down(i);
    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[n--];
        down(1);
    }
    return 0;
}

void down(int u) {
    int t = u;
    if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}