N, S, D = map(int, input().split())
A = list(map(int, input().split()))
arr = [0, 0]
for x in A: arr.append(arr[-1] + x)
ans = 1
for L in range(1, S+1):
  for R in range(S, N+1):
    if arr[R] - arr[L] + min(arr[R]-arr[S], arr[S]-arr[L]) <= D:
      ans = max(ans, R-L+1)
print(ans)