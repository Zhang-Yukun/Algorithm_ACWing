#include <iostream>
#include <cstring>
using namespace std;

const int N = 11, M = 1010;
int n, m, len, res, dp[N][N];
char s[M][N], q[N];

int cal_edit_distance(char a[], char b[]);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i] + 1);
    while (m--) {
        scanf("%s%d", q + 1, &len);
        res = 0;
        for (int i = 0; i < n; i++) {
            if (cal_edit_distance(s[i], q) <= len) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}

int cal_edit_distance(char a[], char b[]) {
    int len_a = strlen(a + 1), len_b = strlen(b + 1);
    for (int i = 1; i <= len_a; i++) dp[i][0] = i;
    for (int j = 1; j <= len_b; j++) dp[0][j] = j;
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return dp[len_a][len_b];
}