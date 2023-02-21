#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n, k;
	cin >> n >> k;
	bool flag1 = false, flag2 = false;
	for(int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		if(l == k)
		{
			flag1 = true;
		}
		if(r == k)
		{
			flag2 = true;
		}
	}
	if(flag1 && flag2)
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
