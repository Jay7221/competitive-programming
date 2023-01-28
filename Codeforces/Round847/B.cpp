#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, s, r;
	cin >> n >> s >> r;
	vector<int> a(n);
	a[0] = s - r;
	int x = (r / (n - 1));
	for(int i = 1; i < n; ++i)
	{
		a[i] = x;
	}
	r -= (n - 1) * x;
	for(int i = 1; i < n; ++i)
	{
		if(r > 0)
		{
			++a[i];
			--r;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
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