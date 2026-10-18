N = int(input())
S = input()
ans = 0
for i in range(1, N+1):
  if S.find('R'*i) != -1:
    ans = i
print(ans)