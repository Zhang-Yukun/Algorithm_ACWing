#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, k, x, n, idx, t, h[N], ph[N], hp[N];
char op[3];

void swap_heap(int u, int v);
void down(int u);
void up(int u);

int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &x);
            n++, idx++;
            h[n] = x;
            hp[n] = idx;
            ph[idx] = n;
            up(n);
        } else if (op[0] == 'P') {
            printf("%d\n", h[1]);
        } else if (op[0] == 'D' && op[1] == 'M') {
            swap_heap(1, n);
            n--;
            down(1);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            t = ph[k];
            swap_heap(t, n);
            n--;
            down(t);
            up(t);
        } else {
            scanf("%d%d", &k, &x);
            t = ph[k];
            h[t] = x;
            down(t);
            up(t);
        }
    }
    return 0;
}

void swap_heap(int u, int v) {
    swap(h[u], h[v]);
    swap(ph[hp[u]], ph[hp[v]]);
    swap(hp[u], hp[v]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) {
        swap_heap(t, u);
        down(t);
    }
}

void up(int u) {
    if (u / 2 && h[u] < h[u / 2]) {
        swap_heap(u / 2, u);
        up(u / 2);
    }
}