#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 3, EMPTY = 0x3f3f3f3f;
int n, x, idx, h[N];
char op[2];

int find(int x);

int main() {
    memset(h, 0x3f, sizeof(h));
    scanf("%d", &n);
    while (n--) {
        scanf("%s%d", op, &x);
        idx = find(x);
        if (op[0] == 'I') h[idx] = x;
        else {
            if (h[idx] == x) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

int find(int x) {
    int t = ((x % N) + N) % N;
    while (h[t] != x && h[t] != EMPTY) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}
