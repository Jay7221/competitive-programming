#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
vector<vector<pair<int, ll> >> graph;
void solve(int t)
{
	int n, q;
	cin >> n;
	vector<ll> arr(n + 1), queries(q);
	ll mx = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
		mx = max(mx, (arr[i] + i - 1) / i);
	}
	cin >> q;
	for(int i = 0; i < q; ++i)
	{
		cin >> queries[i];
		if(queries[i] < mx)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << (queries[i] + arr[n] - 1) / queries[i] << '\n';
		}
	}
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
