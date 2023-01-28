#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n;
	cin >> n;
	ll d = 2 * n;
	vector<ll> a(n);
	ll cur = d;
	for(int i = 1; i < n; i += 2)
	{
		a[i] = cur;
		a[i - 1] = d - cur;
		--cur;
	}
	if(n % 2)
	{
		a[n - 1] = n;
	}
	cur = d * d - accumulate(a.begin(), a.end(), 0ll);
	cur /= n;
	for(int i = 0; i < n; ++i)
	{
		a[i] += cur;
	}
	for(ll elem : a)
	{
		cout << elem << ' ';
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