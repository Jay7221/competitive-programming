t = int(input())
def solve(i):
	n = int(input())
	k = (9 - (n % 9)) % 9
	m = 0
	s = 1
	p = True
	while(n > 0):
		t = n % 10
		if p and k > t and k != 0:
			m += s * k;
			s = s * 10
			m += s * 10
			p = False
		else:
			m += s * t
		n = int(n / 10)
		s = s * 10
	if p and k != 0:
		m += s * k

	print("Case #", i, ":", m)

for i in range(t):
	solve(i + 1)