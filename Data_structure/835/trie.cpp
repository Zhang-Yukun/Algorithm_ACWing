#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, idx, t[N][26], cnt[N];
char op[2], x[N];

void insert(char x[]);
int query(char x[]);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", op, x);
        if (op[0] == 'I') insert(x);
        else printf("%d\n", query(x));
    }
    return 0;
}

void insert(char x[]) {
    int loc = 0, val = 0;
    for (int i = 0; x[i]; i++) {
        val = x[i] - 'a';
        if (!t[loc][val]) t[loc][val] = ++idx;
        loc = t[loc][val];
    }
    cnt[loc]++;
}

int query(char x[]) {
    int loc = 0, val = 0;
    for (int i = 0; x[i]; i++) {
        val = x[i] - 'a';
        if (!t[loc][val]) return 0;
        loc = t[loc][val];
    }
    return cnt[loc];
}