# KMP字符串

给定一个字符串 $S$，以及一个模式串 $P$，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模式串 $P$ 在字符串 $S$ 中多次作为子串出现。

求出模式串 $P$ 在字符串 $S$ 中所有出现的位置的起始下标。

## 输入格式

第一行输入整数 $N$，表示字符串 $P$ 的长度。

第二行输入字符串 $P$。

第三行输入整数 $M$，表示字符串 $S$ 的长度。

第四行输入字符串 $S$。

## 输出格式

共一行，输出所有出现位置的起始下标（下标从 $0$ 开始计数），整数之间用空格隔开。

## 数据范围

$$1 \le N\le 10^5
\\
1 \le M \le 10^6
$$

## 输入样例：

```text
3
aba
5
ababa
```

## 输出样例：

```text
0 2
```

## Solution

```Cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, ne[N];
char p[N], s[N];

int main() {
    scanf("%d%s%d%s", &n, p, &m, s);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && p[j] != p[i]) j = ne[j - 1];
        if (p[i] == p[j]) j++;
        ne[i] = j;
    }
    for (int i = 0, j = 0; i < m; i++) {
        while (j && p[j] != s[i]) j = ne[j - 1];
        if (p[j] == s[i]) j++;
        if (j == n) {
            printf("%d ", i - j + 1);
            j = ne[j - 1];
        }
    }
    return 0;
}
```