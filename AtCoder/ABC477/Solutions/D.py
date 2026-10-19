N, Q = map(int, input().split())
last = [-2 for i in range(N)]
tile = [0 for i in range(N)]
res = ['a' for i in range(N)]
op, char = -1, 'a'
for _ in range(Q):
  otype, oparam = input().split()
  if int(otype) == 1:
    X = int(oparam)
    if tile[X-1] == 0:
      tile[X-1] = 1
      if last[X-1] < op:
        res[X-1] = char
    else:
      last[X-1] = _
      tile[X-1] = 0
  else:
    op = _
    char = oparam
for i in range(N):
  if tile[i] == 0 and op > last[i]:
    res[i] = char
print(''.join(res))
