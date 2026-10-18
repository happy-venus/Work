N = int(input())
y = []
for x in map(int, input().split()):
  y.append(x)
  y.sort()
  if len(y) > 3:
    y = y[1:]
  if len(y) == 3:
    print(y[0])