#include <stdio.h>
#include <string.h>

#define N 100020
char sa[N];
int a[N], a_len, b, c[N], c_len;

void mul(int a[], int a_len, int b);

int main() {
    scanf("%s%d", sa, &b);
    a_len = strlen(sa);
    for (int i = a_len - 1, j = 0; i > -1; i--) a[j++] = sa[i] - '0';
    mul(a, a_len, b);
    for (int i = c_len - 1; i > -1; i--) printf("%d", c[i]);
    return 0;
}

void mul(int a[], int a_len, int b) {
    int j = 0, t = 0;
    for (int i = 0; i < a_len; i++) {
        j = i;
        t = a[i] * b;
        do {
            c[j] += (t % 10);
            t /= 10;
            if (c[j] > 9) {
                c[j] %= 10;
                t++;
            }
            j++;
        } while (t);
    }
    while ((j - 1) && (c[j - 1] == 0)) j--;
    c_len = j;
}