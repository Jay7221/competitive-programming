#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	multiset<ll> s;
	for(int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		s.insert(a);
	}
	for(int i = 0; i < m; ++i)
	{
		ll b;
		cin >> b;
		s.erase(s.begin());
		s.insert(b);
	}
	for(ll elem : s)
	{
		sum += elem;
	}
	cout << sum << '\n';
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