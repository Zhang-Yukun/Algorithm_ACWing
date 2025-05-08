#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, idx, hh, tt, h[N], e[N], ne[N], cnt[N], q[N];

void add(int a, int b);
bool topsort(int n);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    if (topsort(n)) {
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
    } else {
        printf("-1");
    }
    return 0;
}

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    cnt[b]++;
}

bool topsort(int n) {
    hh = tt = 0;
    int t = 0, j = 0;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) q[tt++] = i;
    }
    while (hh < tt) {
        t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            j = e[i];
            cnt[j]--;
            if (!cnt[j]) q[tt++] = j;
        }
    }
    return tt == n;
}