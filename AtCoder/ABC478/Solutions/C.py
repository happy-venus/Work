N, K = map(int, input().split())
A = list(map(int, input().split()))
B = A.copy()
B.sort()
arr = []
for i in range(N):
  if A[i] != B[i]:
    arr.append(i)
if len(arr) == 0 or arr[-1] - arr[0] <= K-1:
  print("Yes")
else:
  print("No")