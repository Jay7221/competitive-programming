#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 7;
ll fact[MAX];
ll mult(ll a, ll b)
{
	return ((a * b) % MOD);
}
void pre()
{
	fact[0] = 1;
	for(int i = 1; i < MAX; ++i)
	{
		fact[i] = mult(fact[i - 1], i);
	}
}
void solve()
{
	ll n;
	cin >> n;
	ll ans = fact[n];
	ans = mult(ans, n);
	ans = mult(ans, n - 1);
	cout << ans << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}