N = int(input())
P = list(map(int, input().split()))
for i in range(0, N, 10):
  if max(P[i:i+10]) > i+10:
    print("No")
    exit(0)
print("Yes")