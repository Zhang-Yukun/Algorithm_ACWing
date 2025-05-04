#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, k, x, idx = 2, e[N], l[N], r[N];
char op[3];

void insert_left_head(int x);
void insert_right_head(int x);
void insert_left(int k, int x);
void insert_right(int k, int x);
void remove(int k);

int main() {
    scanf("%d", &m);
    r[0] = 1, l[1] = 0;
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'L') {
            scanf("%d", &x);
            insert_left_head(x);
        } else if (op[0] == 'R') {
            scanf("%d", &x);
            insert_right_head(x);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            remove(k + 1);
        } else if (op[1] == 'L') {
            scanf("%d%d", &k, &x);
            insert_left(k + 1, x);
        } else {
            scanf("%d%d", &k, &x);
            insert_right(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
    return 0;
}

void insert_left_head(int x) {
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[0]] = idx;
    r[0] = idx++;
}

void insert_right_head(int x) {
    e[idx] = x;
    l[idx] = l[1];
    r[idx] = 1;
    r[l[1]] = idx;
    l[1] = idx++;
}

void insert_left(int k, int x) {
    e[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    r[l[k]] = idx;
    l[k] = idx++;
}

void insert_right(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
