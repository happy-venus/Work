N, D = map(int, input().split())
X = list(map(int, input().split()))
arr = []
for i in range(N):
  flag = True
  for j in range(N):
    if i != j and abs(X[i]-X[j]) < D:
      flag = False
  if flag: arr.append(i+1)
print(len(arr))
print(*arr)