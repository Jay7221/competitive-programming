s = input()
n = len(s)
freq = [0] * 26
ans = 0
l = 0
for i in range(n):
    c = ord(s[i]) - ord('a')
    freq[c] += 1
    while freq[c] > 2:
        freq[ord(s[l]) - ord('a')] -= 1
        l += 1
    ans = max(ans, i - l + 1)

print(ans)
