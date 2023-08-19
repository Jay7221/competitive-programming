#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	auto query = [&](int i)
	{
		cout << "? " << i << endl;
		ll ans;
		cin >> ans;
		return ans;
	};
	auto reply = [&](vector<ll> &b)
	{
		cout << "! ";
		int n = b.size();
		for(int i = 0; i < n - 1; ++i)
		{
			cout << b[i] << ' ';
		}
		cout << b[n - 1];
		cout << endl;
	};
	int k, n;
	cin >> k >> n;
	vector<ll> b(n), a(k + 1);
	vector<bool> vis(k + 1);
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		b[i] = b[i] % (k + 1);
		vis[b[i]] = 1;
	}
	int cnt = 0;
	for(int i = 0; i < k; ++i)
	{
		if(vis[i])
		{
			++cnt;
			a[i] = query(i);
		}
	}
	if(vis[k])
	{
		if(cnt < k)
		{
			a[k] = query(k);
		}
		else
		{
			for(int i = 0; i < k; ++i)
			{
				a[k] -= a[i];
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		b[i] = a[b[i]];
	}
	reply(b);
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