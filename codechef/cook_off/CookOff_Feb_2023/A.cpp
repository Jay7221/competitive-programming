#include<bits/stdc++.h>
using namespace std;

void solve()
{
	map<int, int> freq;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		++freq[a];
	}
	bool flag = false;
	for(auto [u, v] : freq)
	{
		if(v % 2 == 1)
		{
			flag = true;
			break ;
		}
	}
	if(flag)
	{
		cout << "Marichka\n";
	}
	else
	{
		cout << "Zenyk\n";
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