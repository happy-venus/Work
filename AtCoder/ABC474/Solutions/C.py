N, Q = map(int, input().split())
P = list(map(int, input().split()))
for _ in range(Q): P.append(int(input()))
vis = [0 for i in range(N+1)]
arr = []
for x in P[::-1]:
  if not vis[x]:
    vis[x] = 1
    arr.append(x)
print(*arr[::-1])