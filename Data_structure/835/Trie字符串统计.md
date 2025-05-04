# Trie字符串统计

维护一个字符串集合，支持两种操作：

1. `I x` 向集合中插入一个字符串 $x$；
2. `Q x` 询问一个字符串在集合中出现了多少次。

共有 $N$ 个操作，所有输入的字符串总长度不超过 $10^5$，字符串仅包含小写英文字母。

## 输入格式

第一行包含整数 $N$，表示操作数。

接下来 $N$ 行，每行包含一个操作指令，指令为 `I x` 或 `Q x` 中的一种。

## 输出格式

对于每个询问指令 `Q x`，都要输出一个整数作为结果，表示 $x$ 在集合中出现的次数。

每个结果占一行。

## 数据范围

$$1 \le N \le 2\times10^4$$

## 输入样例：

```text
5
I abc
Q abc
Q ab
I ab
Q ab
```

## 输出样例：

```text
1
0
1
```

## Solution
```Cpp
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
```