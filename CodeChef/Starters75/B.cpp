#include<bits/stdc++.h>
using namespace std;
#define ll long long
// const int MAX = 3e5 + 7;
class Modulo
{
	public:
		ll MOD;
		const static int MAX = 3e5 + 7;
		vector<ll> fact, invFact, inv;
		Modulo(int m)
		{
			this -> MOD = m;
			fact.assign(MAX, 1);
			invFact.assign(MAX, 1);
			inv.assign(MAX, 1);
			for(int i = 2; i < MAX; ++i)
			{
				int r = MOD % i;
				int q = MOD / i;
				inv[i] = mult(q, sub(MOD, inv[r]));
				fact[i] = mult(fact[i - 1], i);
				invFact[i] = mult(invFact[i - 1], inv[i]);
			}
		}
		ll add(ll a, ll b)
		{
			return ((a + b) % MOD);
		}
		ll sub(ll a, ll b)
		{
			return ((((a - b) % MOD) + MOD) % MOD);
		}
		ll mult(ll a, ll b)
		{
			return ((a * b) % MOD);
		}
		ll pow(ll a, ll p)
		{
			ll ans = 1, res = a;
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
		ll com(ll n, ll r)
		{
			if(n < r)
			{
				return 0ll;
			}
			ll ans = mult(fact[n], mult(invFact[r], invFact[n - r]));
			return ans;
		}
};
Modulo M(1e9 + 7);
void solve()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int s = 0, d = 0;
	for(int i = 0; i < n; ++i)
	{
		s += (a[i] == b[i]);
		d += (a[i] != b[i]);
	}
	int ans;
	if(d % 2)
	{
		ans = 0;
	}
	else
	{
		ans = M.mult(M.pow(2, s), M.com(d, d / 2));
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