#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	vector<ll> power(n), health(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> health[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> power[i];
	}
	for(int i = 0; i < n; ++i)
	{
		v[i] = {power[i], health[i]};
	}
	sort(v.begin(), v.end());
	bool flag = true;
	ll curDamage = k;
	// bool damage = false;
	for(auto [p, h] : v)
	{
		while((h > curDamage) && (k > p))
		{
			k -= p;
			curDamage += k;
		}
		if(h > curDamage)
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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