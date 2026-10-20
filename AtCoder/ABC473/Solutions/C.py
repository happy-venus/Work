N, K = map(int, input().split())
A = list(map(int, input().split()))
cnt = {x : 0 for x in A}
for x in A: cnt[x] += 1
mx = max(cnt.values())
ans = 0
for x in cnt:
  if cnt[x] >= mx-1:
    ans += 1
print(ans)