N, M = map(int, input().split())
S = [input() for i in range(N)]
vote = {x : 0 for  x in S}
for _ in range(M):
	name = input()
	if name in vote:
		vote[name] += 1
	else:
		nameset = set()
		for i in range(len(name)):
			for c in 'abcdefghijklmnopqrtstuvwxyz':
				cname = name[:i] + c + name[i+1:]
				if cname in vote:
					nameset.add(cname)
		if len(nameset) == 1:
			for x in nameset:
				vote[x] += 1
for _ in S: print(vote[_])
