#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, x, h, t, q[N];
char op[10];

void push(int x);
void pop();
bool empty();
int query();

int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%d", &x);
            push(x);
        } else if (op[0] == 'p') {
            pop();
        } else if (op[0] == 'e') {
            if (empty()) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("%d\n", query());
        }
    }
    return 0;
}

void push(int x) {
    q[t++] = x;
}

void pop() {
    h++;
}

bool empty() {
    return h == t;
}

int query() {
    return q[h];
}