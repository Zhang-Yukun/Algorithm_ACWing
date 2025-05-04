#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, k, x, h, idx = 1, e[N], ne[N];
char op[2];

void insert_head(int x);
void insert(int k, int x);
void remove(int k);

int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'H') {
            scanf("%d", &x);
            insert_head(x);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            remove(k);
        } else {
            scanf("%d%d", &k, &x);
            insert(k, x);
        }
    }
    for (int i = h; i; i = ne[i]) printf("%d ", e[i]);
    return 0;
}

void insert_head(int x) {
    e[idx] = x;
    ne[idx] = h;
    h = idx++;
}

void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k) {
    if (k == 0) {
        h = ne[h];
    } else {
        ne[k] = ne[ne[k]];
    }
}