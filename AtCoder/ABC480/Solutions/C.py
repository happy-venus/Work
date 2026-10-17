N, K, T = map(int, input().split())
A = list(map(int, input().split())) + [T,]
A.sort()
cur, ans = 0, 0
for x in A:
	if x > T:
		break
	con = max(0, x-cur)
	cur = x+K
	ans += (con+K-1)//K
print(ans)