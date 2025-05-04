#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, x, h, t, q[N];
char op[10];

int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%d", &x);
            q[t++] = x;
        } else if (op[0] == 'p') {
            h++;
        } else if (op[0] == 'e') {
            if (h == t) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("%d\n", q[h]);
        }
    }
    return 0;
}