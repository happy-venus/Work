N, W = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
ans = 0
for mask in range(1<<N):
	deli, wei = 0, 0
	for i in range(N):
		if mask & (1<<i):
			deli += arr[i][0]
			wei += arr[i][1]
	if wei <= W:
		ans = max(ans, deli)
print(ans)