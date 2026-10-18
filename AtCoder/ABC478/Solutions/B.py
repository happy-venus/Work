N, V = map(int, input().split())
W = list(map(int, input().split()))
ans = 0
for i in range(N):
  for j in range(N):
    for k in range(N):
      if len(set([i, j, k])) == 3 and i+j+k <= V-3:
        ans = max(ans, W[i]+W[j]+W[k])
print(ans)
