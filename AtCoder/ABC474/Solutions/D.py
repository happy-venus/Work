N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
for i in range(N):
  if A[i] > B[i]:
    W = [1 for _ in range(N)]
    W[i] = 10**18
    print("Yes")
    print(*W)
    exit(0)
print("No")