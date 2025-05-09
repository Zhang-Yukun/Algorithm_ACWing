#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, head, tail, idx, h[N], e[N], ne[N], q[N], cnt[N];

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
    } else printf("-1");
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++, cnt[b]++;
}

bool topsort(int n) {
    head = tail = 0;
    int node;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) q[tail++] = i;
    }
    while (head < tail) {
        node = q[head++];
        for (int i = h[node]; i != -1; i = ne[i]) {
            cnt[e[i]]--;
            if (!cnt[e[i]]) q[tail++] = e[i];
        }
    }
    return tail == n;
}