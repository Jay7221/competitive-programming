#include<bits/stdc++.h>
using namespace std;

#define ll long long
int MOD = 998244353;

int add(int a, int b)
{
	return ((a + b) % MOD);
}
int sub(int a, int b)
{
	return ((((a - b) % MOD) + MOD) % MOD);
}
int mult(int a, int b)
{
	return (((ll)a * (ll)b) % MOD);
}
int power(int a, int p)
{
	int ans = 1, res = a;
	while(p)
	{
		if(p & 1)
		{
			ans = mult(ans, res);
		}
		res = mult(res, res);
		p >>= 1;
	}
	return ans;
}
int inv(int a)
{
	return power(a, MOD - 2);
}
int divide(int a, int b)
{
	return mult(a, inv(b));
}


void solve()
{
	int n;
	cin >> n;
	string A, B;
	cin >> A >> B;
	int x = 0;
	for(int i = 0; i < n; ++i)
	{
		x += (A[i] != B[i]);
	}
	vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
	a[0] = b[0] = 0;
	for(int k = 1; k < n; ++k)
	{
		a[k] = divide(add(n, mult(k, a[k - 1])), sub(n, mult(k, b[k - 1])));
		b[k] = divide(sub(n, k), sub(n, mult(k, b[k - 1])));
	}
	c[n] = d[n] = 1;
	for(int k = n - 1; k >= 1; --k)
	{
		c[k] = divide(add(n, mult(n - k, c[k + 1])), sub(n, mult(n - k, d[k + 1])));
		d[k] = divide(k, sub(n, mult(n - k, d[k + 1])));
	}
	int ans = 0;
	if(x > 0)
	{
		ans = divide(add(c[x], mult(a[x - 1], d[x])), sub(1, mult(b[x - 1], d[x])));
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}