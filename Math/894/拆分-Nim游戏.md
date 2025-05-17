# 拆分-Nim游戏

给定 $n$ 堆石子，两位玩家轮流操作，每次操作可以取走其中的一堆石子，然后放入两堆规模更小的石子（新堆规模可以为 $0$，且两个新堆的石子总数可以大于取走的那堆石子数），最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

## 输入格式

第一行包含整数 $n$。

第二行包含 $n$ 个整数，其中第 $i$ 个整数表示第 $i$ 堆石子的数量 $a_i$。

## 输出格式

如果先手方必胜，则输出 `Yes`。

否则，输出 `No`。

## 数据范围

$$
1 \le n,a_i \le 100
$$

## 输入样例：

```text
2
2 3
```

## 输出样例：

```text
Yes
```

## Solution

```Cpp
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110;
int n, a, res, f[N];

int sg(int x);

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        res ^= sg(a);
    }
    if (res) printf("Yes");
    else printf("No");
    return 0;
}

int sg(int x) {
    if (f[x] != -1) return f[x];
    unordered_set<int> s;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            s.insert(sg(i) ^ sg(j));
        }
    }
    for (int i = 0; ; i++) {
        if (!s.count(i)) {
            return f[x] = i;
        }
    }
}
```
