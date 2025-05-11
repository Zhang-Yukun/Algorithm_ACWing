#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n1, n2, m, x, y, res, idx, h[N], e[N], ne[N], match[N];
bool v[N];

void add(int a, int b);
bool find(int x);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d%d", &n1, &n2, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for (int i = 1; i <= n1; i++) {
        memset(v, false, sizeof(v));
        if (find(i)) res++;
    }
    printf("%d", res);
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        if (!v[e[i]]) {
            v[e[i]] = true;
            if (!match[e[i]] || find(match[e[i]])) {
                match[e[i]] = x;
                return true;
            }
        }
    }
    return false;
}