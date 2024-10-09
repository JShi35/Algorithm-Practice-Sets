n, m = map(int, input().split())
E = [int(input()) for _ in range(n)]
A = [int(input()) for _ in range(m)]

dp = [[0] * (m + 1) for _ in range(n + 1)]

def get_score(t_diff):
    if t_diff > 102:
        return 0
    if t_diff <= 15:
        return 7
    elif t_diff <= 23:
        return 6
    elif t_diff <= 43:
        return 4
    else:
        return 2

for i in range(1, n + 1):
    for j in range(1, m + 1):
        t_diff = abs(E[i - 1] - A[j - 1])
        s = get_score(t_diff)
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + s)

print(dp[n][m])
