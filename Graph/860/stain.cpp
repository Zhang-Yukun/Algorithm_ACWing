#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, idx, h[N], e[2 * N], color[N], ne[2 * N];
bool flag = true;

void add(int a, int b);
bool stain(int u, int c);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!stain(i, 1)) {
                flag = false;
                break;
            }
        }
    }
    if (flag) printf("Yes");
    else printf("No");
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool stain(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        if (!color[e[i]]) {
            if (!stain(e[i], 3 - c)) return false;
        } else if (color[e[i]] == c) return false;
    }
    return true;
}