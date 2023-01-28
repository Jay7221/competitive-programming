#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> p(n + 1);
	int l = 1, r = n;
	for(int i = 1; i <= n; ++i)
	{
		if(i % k == 0)
		{
			p[i] = l;
			++l;
		}
		else
		{
			p[i] = r;
			--r;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		cout << p[i] << ' ';
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