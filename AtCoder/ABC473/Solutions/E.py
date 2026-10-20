N, K = map(int, input().split())
A = list(map(int, input().split()))
pre = [0]
for x in A: pre.append((pre[-1] + x) % K)
pos = {x : -1 for x in pre}
dp = [0 for _ in range(N+1)]
for i in range(1, N+1):
  pos[pre[i-1]] = i-1
  dp[i] = dp[i-1]
  if pos[pre[i]] == -1:
    continue
  dp[i] = max(dp[pos[pre[i]]] + 1, dp[i])
print(dp[N])