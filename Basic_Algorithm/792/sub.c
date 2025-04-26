#include <stdio.h>
#include <string.h>

#define N 100005

char sa[N], sb[N];
int a[N], a_len, b[N], b_len, c[N], c_len, flag;

int cmp(int a[], int a_len, int b[], int b_len);
void sub(int a[], int a_len, int b[], int b_len);

int main() {
    scanf("%s%s", sa, sb);
    a_len = strlen(sa);
    b_len = strlen(sb);
    for (int i = a_len - 1,j = 0; i > -1; i--) a[j++] = sa[i] - '0';
    for (int i = b_len - 1,j = 0; i > -1; i--) b[j++] = sb[i] - '0';
    flag = cmp(a, a_len, b, b_len);
    if (flag > 0) {
        sub(a, a_len, b, b_len);
        for (int i = c_len - 1; i > -1; i--) printf("%d", c[i]);
    } else if (flag < 0) {
        sub(b, b_len, a, a_len);
        printf("-");
        for (int i = c_len - 1; i > -1; i--) printf("%d", c[i]);
    } else {
        printf("0");
    }
    return 0;
}

int cmp(int a[], int a_len, int b[], int b_len) {
    if (a_len < b_len) return -1;
    else if (a_len > b_len) return 1;
    else {
        for (int i = a_len; i > -1; i--) {
            if (a[i] > b[i]) return 1;
            else if (a[i] < b[i]) return -1;
            else continue;
        }
    }
    return 0;
}

void sub(int a[], int a_len, int b[], int b_len) {
    // suppose a is larger than b
    int i = 0;
    while (i < b_len) {
        c[i] = a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 10;
            a[i + 1]--;
        }
        i++;
    }
    while (i < a_len) {
        c[i] = a[i];
        if (c[i] < 0) {
            c[i] += 10;
            a[i + 1]--;
        }
        i++;
    }
    while (i && (c[i - 1] == 0)) i--;
    c_len = i;
}
