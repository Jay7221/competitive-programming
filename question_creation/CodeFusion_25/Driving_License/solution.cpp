#include<bits/stdc++.h>
using namespace std;
#define ll long long
int INF = 1e9 + 7;
void solve(int t)
{
	int n;
	cin >> n;
	int l = 0, r = INF;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;
		if(ch == '0')
		{
			l = max(l, a[i] + 1);
		}
		else
		{
			r = min(r, a[i]);
		}
	}
	cout << l << '\n';
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
