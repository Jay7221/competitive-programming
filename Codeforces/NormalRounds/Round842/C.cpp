#include<bits/stdc++.h>
using namespace std;
bool solve()
{
	int n;
	cin >> n;
	vector<int> a(n), freq(n + 1), b(n), v0, v2, mp(n + 1);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++freq[a[i]];
	}
	for(int p = 1; p <= n; ++p)
	{
		if(freq[p] == 1)
		{
			mp[p] = p;
		}
		else if(freq[p] == 2)
		{
			v2.push_back(p);
		}
		else if(freq[p] == 0)
		{
			v0.push_back(p);
		}
		else
		{
			return false;
		}
	}
	for(int i = 0; i < v0.size(); ++i)
	{
		if(v2[i] < v0[i])
		{
			return false;
		}
		mp[v2[i]] = v0[i];
	}
	vector<bool> vis(n + 1);
	for(int i = 0; i < n; ++i)
	{
		int p = a[i];
		if(freq[p] == 1)
		{
			a[i] = b[i] = p;
		}
		else
		{
			if(vis[p])
			{
				a[i] = mp[p];
				b[i] = p;
			}
			else
			{
				vis[p] = 1;
				a[i] = p;
				b[i] = mp[p];
			}
		}
		if(max(a[i], b[i]) != p)
		{
			return false;
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i < n; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << '\n';
	return true;
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
		if(!solve())
		{
			cout << "NO\n";
		}
	}
	return 0;
}