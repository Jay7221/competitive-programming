#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> b(n), a(n);
	map<int, int> freq, mp;
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
		++freq[b[i]];
	}
	int cur = 1;
	for(auto elem : b)
	{
		if(freq[elem] % elem)
		{
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		if(freq[b[i]] % b[i] == 0)
		{
			mp[b[i]] = cur;
			++cur;
		}
		a[i] = mp[b[i]];
		--freq[b[i]];
	}
	for(auto elem : a)
	{
		cout << elem << ' ' ;
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