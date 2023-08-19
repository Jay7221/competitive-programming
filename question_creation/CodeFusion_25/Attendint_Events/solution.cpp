#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int t)
{
	int n, m;
	cin >> n >> m;
	priority_queue<ll> pq;
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		a = a * -1;
		if(pq.size() == m)
		{
			ll u = pq.top();
			pq.pop();
			pq.push(u + a);
			ans = min(ans, u + a);
		}
		else
		{
			ans = min(ans, a);
			pq.push(a);
		}
	}
	ans = ans * -1;
	cout << ans << '\n';
}
int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		solve(t);
	}
	return 0;
}
