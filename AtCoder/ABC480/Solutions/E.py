N = int(input())

ans = 0

def multiply(a, d, n):
	r = 1
	for i in range(n):
		r *= a
		a += d
	return r

for len in range(3, 100):
	for s in range(1, 10**7):
		st, ed = 0, 10**10
		while st < ed:
			md = (st + ed) // 2
			if multiply(s, md+1, len) <= N:
				st = md+1
			else:
				ed = md
		ans += st
		if st == 0:
			break
print(ans)