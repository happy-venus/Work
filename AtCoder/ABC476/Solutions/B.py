N, S, T = int(input()), input(), input()
for i in range(N):
  if S[i] != T[i] and T[i] != '*':
    print('No')
    exit(0)
print('Yes')