N, Q = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
arr = [0 for _ in range(N+1)]
arrN = [B[_] for _ in range(N)]
for i in range(N): arr[i+1] = arr[i] + A[i]
for i in range(N)[::-1]: arrN[i] = min(arrN[(i+1)%N] + A[i], arrN[i])
for i in range(N)[::-1]: arrN[i] = min(arrN[(i+1)%N] + A[i], arrN[i])
for i in range(N): arrN[(i+1)%N] = min(arrN[(i+1)%N], arrN[i] + A[i])
for i in range(N): arrN[(i+1)%N] = min(arrN[(i+1)%N], arrN[i] + A[i])
for _ in range(Q):
  u, v = map(int, input().split())
  if v == N+1:
    print(arrN[u-1])
  else:
    print(min(abs(arr[u-1]-arr[v-1]), arr[N]-abs(arr[u-1]-arr[v-1]), arrN[u-1]+arrN[v-1]))