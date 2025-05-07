#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

const int N = 1e2 + 10;
int n, m, h, t, g[N][N], d[N][N];
pair<int, int> q[N * N];

int bfs(int g[][N]);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
    }
    printf("%d", bfs(g));
    return 0;
}

int bfs(int g[][N]) {
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    int x = 0, y = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    pair<int, int> node;
    q[t++] = {0, 0};
    while (h < t) {
        node = q[h++];
        for (int i = 0; i < 4; i++) {
            x = node.first + dx[i];
            y = node.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1) {
                q[t++] = {x, y};
                d[x][y] = d[node.first][node.second] + 1;
            }
        }
    }
    return d[n - 1][m - 1];
}