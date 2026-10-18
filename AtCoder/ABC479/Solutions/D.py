N, Q = map(int, input().split())
L = list(map(int, input().split()))
R = list(map(int, input().split()))
pre, suf = [10**9 for i in range(N)], [10**9 for i in range(N)]
for i in range(N-1):
  pre[i+1] = min(pre[i], R[i])
for i in range(N-1)[::-1]:
  suf[i] = min(suf[i+1], L[i]);
for _ in range(Q):
  s, t = map(int, input().split())
  cur = (R[s-1] if s < t else L[s-2])
  if min(s, t) > 1:
    cur = min(cur, L[s-2] + pre[min(s, t) - 1])
  if max(s, t) < N:
    cur = min(cur, R[s-1] + suf[max(s, t) - 1])
  print(cur)