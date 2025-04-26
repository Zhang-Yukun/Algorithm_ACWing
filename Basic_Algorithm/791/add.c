#include <stdio.h>
#include <string.h>

#define N 100005

char sa[N], sb[N];
int a[N], b[N], res[N], a_len, b_len, res_len;

int add(int a[], int a_len, int b[], int b_len);

int main() {
    scanf("%s%s", sa, sb);
    a_len = strlen(sa);
    b_len = strlen(sb);
    for (int i = 0; i < strlen(sa); i++) a[i] = sa[i] - '0';
    for (int i = 0; i < strlen(sb); i++) b[i] = sb[i] - '0';
    res_len = add(a, a_len, b, b_len);
    for (int i = res_len - 1; i > -1; i--) printf("%d", res[i]);
    return 0;
}

int add(int a[], int a_len, int b[], int b_len) {
    int i = a_len - 1, j = b_len - 1, k = 0, sum = 0;
    while ((i > -1) && (j > -1)) {
        sum = a[i--] + b[j--] + res[k];
        res[k++] = sum % 10;
        res[k] = sum / 10;
    }
    while (i > -1) {
        sum = a[i--] + res[k];
        res[k++] = sum % 10;
        res[k] = sum / 10;
    }
    while (j > -1) {
        sum = b[j--] + res[k];
        res[k++] = sum % 10;
        res[k] = sum / 10;
    }
    return res[k] == 0 ? k : k + 1;
}