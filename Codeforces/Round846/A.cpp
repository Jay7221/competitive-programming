#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	stack<int> even, odd;
	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		if(a % 2)
		{
			odd.push(i);
		}
		else
		{
			even.push(i);
		}
	}
	if(odd.size() >= 3)
	{
		cout << "YES\n";
		for(int i = 0; i < 3; ++i)
		{
			cout << odd.top() << ' ';
			odd.pop();
		}
		cout << '\n';
	}
	else if((odd.size() >= 1) && (even.size() >= 2))
	{
		cout << "YES\n";
		for(int i = 0; i < 2; ++i)
		{
			cout << even.top() << ' ' ;
			even.pop();
		}
		cout << odd.top() << '\n';
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