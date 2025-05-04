#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, x, t, s[N];
char op[10];

int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%d", &x);
            s[t++] = x;
        } else if (op[0] == 'p') {
            t--;
        } else if (op[0] == 'e') {
            if (!t) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("%d\n", s[t - 1]);
        }
    }
    return 0;
}
