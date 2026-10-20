class SegTree:
  def __init__(self, n):
    self.sz = 1
    while self.sz < n:
      self.sz *= 2
    self.seg = [(0, 0) for _ in range(self.sz*2)]
    self.func = lambda x, y: (x[0]+y[0], min(x[1], x[0]+y[1]))

  def Set(self, i, x):
    i += self.sz - 1
    self.seg[i] = (x, min(x, 0))
    while i > 2:
      i //= 2
      self.seg[i] = self.func(self.seg[i*2], self.seg[i*2+1])

  def _Get(self, l, r, i, L, R):
    if l == L and r == R:
      return self.seg[i]
    md = (L + R) // 2
    if r <= md: return self._Get(l, r, i*2, L, md)
    elif l > md: return self._Get(l, r, i*2+1, md+1, R)
    else: return self.func(self._Get(l, md, i*2, L, md), self._Get(md+1, r, i*2+1, md+1, R))

  def Get(self, l, r):
    return self._Get(l, r, 1, 1, self.sz)[1]
    

import sys
input = sys.stdin.readline
print = sys.stdout.write
func = lambda x: +1 if x == 'A' else -1
N, S, Q = int(input()), list(map(func, input())), int(input())
ST = SegTree(N)
for i in range(N):
  ST.Set(i+1, S[i])
for _ in range(Q):
  op, p1, p2 = input().split()
  if op == '1':
    p1 = int(p1)
    ST.Set(p1, func(p2))
  else:
    p1, p2 = int(p1), int(p2)
    if ST.Get(p1, p2) >= 0:
      print('Yes\n')
    else:
      print('No\n')
