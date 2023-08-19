#include<bits/stdc++.h>
using namespace std;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n;
	cin >> n;
	n /= 2;
	vector<int> b(n), p(2 * n);
	set<int> s;
	for(int i = 1; i <= 2 * n; ++i)
	{
		s.insert(i);
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
		s.erase(b[i]);
	}
	bool flag = true;
	if(s.size() != n)
	{
		flag = false;
	}
	for(int i = n - 1; i > -1; --i)
	{
		p[2 * i + 1] = b[i];
		if(s.upper_bound(b[i]) == s.begin())
		{
			flag = false;
			break;
		}
		else
		{
			p[2 * i] = *(--s.upper_bound(b[i]));
			s.erase(p[2 * i]);
		}
	}
	if(flag)
	{
		for(auto elem : p)
		{
			cout << elem << ' ';
		}
		cout << '\n';
	}
	else
	{
		cout << -1 << '\n';
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