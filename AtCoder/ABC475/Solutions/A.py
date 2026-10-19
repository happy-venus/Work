S = input()
T = [S[i//2] if i % 2 == 0 else 'o' for i in range(2*len(S)-1)]
print(''.join(T))