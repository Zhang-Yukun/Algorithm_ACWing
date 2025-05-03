#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, x, idx, s[N];
char op[10];


void push(int x);
void pop();
bool empty();
int query();

int main() {
    idx = -1;
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
    s[++idx] = x;
}

void pop() {
    idx--;
}

bool empty() {
    return idx == -1;
}

int query() {
    return s[idx];
}

