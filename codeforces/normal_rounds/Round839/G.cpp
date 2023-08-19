#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e5 + 7;
void solve()
{
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	auto get = [&](ll cur)
	{
		// number people that will be defeated with rating cur
		int ans = upper_bound(a.begin(), a.end(), cur) - a.begin();
		return ans;
	};
	ll cur = x;
	if((get(cur) + cur < y) && (get(cur) * 2 <= n))
	{
		cout << -1 << '\n';
		return ;
	}
	while(cur < y)
	{
		int p = get(cur);
		ll diff = y - cur;
		
	}
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