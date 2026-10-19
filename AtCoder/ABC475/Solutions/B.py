N = int(input())
A = list(map(int, input().split()))
B = [0, 0, 0]
for x in A:
  y = (x + 999) // 1000
  c = str(y*1000-x).rjust(3, '0')
  for i in range(3):
    B[i] += int(c[i])
print(*B[::-1])