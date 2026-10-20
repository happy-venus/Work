N, A = int(input()), list(map(int, input().split()))
cnt = {x : 0 for x in A}
for x in A: cnt[x] += 1
ans = 0
for k in cnt:
  ans += k * (cnt[k] % 2)
print(ans)