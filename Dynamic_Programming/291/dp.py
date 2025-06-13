if __name__ == "__main__":
    N = 12
    M = 1 << N
    st = [False] * M
    n, m = map(int, input().split())
    while n or m:
        for i in range(1 << n):
            cnt = 0
            st[i] = True
            for j in range(n):
                if i >> j & 1:
                    if cnt & 1:
                        st[i] = False
                        break
                    cnt = 0
                else:
                    cnt += 1
            if cnt & 1:
                st[i] = False
        dp = [[0] * (1 << n) for _ in range(m + 1)]
        dp[0][0] = 1
        for i in range(1, m + 1):
            for j in range(1 << n):
                for k in range(1 << n):
                    if (j & k) == 0 and st[j | k]:
                        dp[i][j] += dp[i - 1][k]
            
        print(dp[m][0])
        n, m = map(int, input().split())
