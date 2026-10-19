Q, S, T = int(input()), input(), input()
cnt = [0 for c in T]
for i in range(len(S)-len(T)+1):
  cnt.append(cnt[-1] + (S[i:i+len(T)] == T))
for _ in range(Q):
  L, R = map(int, input().split())
  print('YNeos'[cnt[R]<=cnt[L+len(T)-2]::2])