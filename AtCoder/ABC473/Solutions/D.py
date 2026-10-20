import sys
input = sys.stdin.readline
print = sys.stdout.write
N, K = map(int, input().split())
ans = []
def dfs(cur = N, sum = K, arr = []):
  if cur == 1:
    ans.append((arr + [sum, ])[::-1])
    return
  for i in range(0, sum+1, cur):
    arr.append(i // cur)
    dfs(cur-1, sum-i, arr);
    arr.pop()
dfs()
ans.sort()
for arr in ans: print(' '.join(map(str, arr)) + '\n')