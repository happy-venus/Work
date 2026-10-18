N, Q = map(int, input().split())
arr = [[] for i in range(N+1)]
for _ in range(Q):
  L, R, X = map(int, input().split())
  arr[L-1].append(X)
  arr[R].append(-X)
cnt = [0 for _ in range(Q+1)]
sz = 0
ans = []
for i in range(N):
  for v in arr[i]:
    c = abs(v)
    sz -= (cnt[c] > 0)
    cnt[c] += v / c
    sz += (cnt[c] > 0)
  ans.append(sz)
print(*ans)