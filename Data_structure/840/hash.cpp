#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 3;
int n, x, idx, h[N], e[N], ne[N];
char op[2];

bool find(int x);
void insert(int x);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    while (n--) {
        scanf("%s%d", op, &x);
        if (op[0] == 'I') insert(x);
        else {
            if (find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

bool find(int x) {
    int t = ((x % N) + N) % N;
    for (int i = h[t]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

void insert(int x) {
    int t = ((x % N) + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx++;
}