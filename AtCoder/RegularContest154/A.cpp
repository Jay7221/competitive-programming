#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll add(ll a, ll b)
{
	return (((a + b) * 1ll) % MOD);
}
ll mult(ll a, ll b)
{
	return ((a * 1ll * b) % MOD);
}
void solve()
{
	int n;
	cin >> n;
	ll a[n], b[n];
	for(int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	for(int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}
	for(int i = 0; i < n; ++i)
	{
		if(a[i] > b[i])
		{
			swap(a[i], b[i]);
		}
	}
	ll A = 0, B = 0;
	for(int i = 0; i < n; ++i)
	{
		A = add(a[i], mult(A, 10));
		B = add(b[i], mult(B, 10));
	}
	int ans = mult(A, B);
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}