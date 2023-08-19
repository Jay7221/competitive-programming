#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n + 2), b(n + 2);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	vector<ll> pre(n + 2), f(n + 2), hf(n + 2), c(n + 2);
	for(int i = 1; i <= n; ++i)
	{
		pre[i] = pre[i - 1] + b[i];
	}
	pre[n + 1] = INF;
	for(int i = 1; i <= n; ++i)
	{
		f[i] += 1;
		int j = lower_bound(pre.begin(), pre.end(), a[i] + pre[i - 1]) - pre.begin();
		f[j] -= 1;
		hf[j] += a[i] - (pre[j - 1] - pre[i - 1]);
	}
	for(int i = 1; i <= n; ++i)
	{
		f[i] += f[i - 1];
	}
	for(int i = 1; i <= n; ++i)
	{
		c[i] = b[i] * f[i] + hf[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		cout << c[i] << ' ';
	}
	cout << '\n';
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
