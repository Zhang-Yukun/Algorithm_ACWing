# n-皇后问题

n−皇后问题是指将 $n$ 个皇后放在 $n \times n$ 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

现在给定整数 $n$，请你输出所有的满足条件的棋子摆法。

## 输入格式
共一行，包含整数 $n$。

## 输出格式

每个解决方案占 $n$ 行，每行输出一个长度为 $n$ 的字符串，用来表示完整的棋盘状态。

其中 . 表示某一个位置的方格状态为空，$Q$ 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

注意：行末不能有多余空格。

输出方案的顺序任意，只要不重复且没有遗漏即可。

## 数据范围

$$1\le n\le 9$$

## 输入样例：

```text
4
```

## 输出样例：

```text
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
```

## Solution

### Solution1

```Cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n;
bool col[N], diag[2 * N], udiag[2 * N];
char g[N][N];

void dfs(int r);

int main() {
    memset(g, '.', sizeof(g));
    scanf("%d", &n);
    dfs(0);
    return 0;
}

void dfs(int r) {
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", g[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag[r + c] && !udiag[n - r + c - 1]) {
            g[r][c] = 'Q';
            col[c] = diag[r + c] = udiag[n - r + c - 1] = true;
            dfs(r + 1);
            g[r][c] = '.';
            col[c] = diag[r + c] = udiag[n - r + c - 1] = false;
        }
    }
}
```

### Solution 2

```Cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n;
bool row[N], col[N], diag[2 * N], udiag[2 * N];
char g[N][N];

void dfs(int x, int y, int k);

int main() {
    memset(g, '.', sizeof(g));
    scanf("%d", &n);
    dfs(0, 0, 0);
    return 0;
}

void dfs(int x, int y, int k) {
    if (y == n) x++, y = 0;
    if (x == n) {
        if (k == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%c", g[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        return;
    }
    dfs(x, y + 1, k);
    if (!row[x] && !col[y] && !diag[x + y] && !udiag[n - x + y - 1]) {
        g[x][y] = 'Q';
        row[x] = col[y] = diag[x + y] = udiag[n - x + y - 1] = true;
        dfs(x, y + 1, k + 1);
        g[x][y] = '.';
        row[x] = col[y] = diag[x + y] = udiag[n - x + y - 1] = false;
    }
}
```