#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int zero, one, two;
	zero = one = two = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i] = (a[i] % 3);
		a[i] = (a[i] * a[i]) % 3;
		if(a[i] == 0)
		{
			++zero;
		}
		else if(a[i] == 1)
		{
			++one;
		}
		else
		{
			++two;
		}
	}
	if((zero == 0) || (zero == n))
	{
		cout << 1 << '\n';
		for(int i = 0; i < n / 2; ++i)
		{
			cout << 10;
		}
		cout << '\n';
	}
	else if(one <= n / 2)
	{
		cout << 2 << '\n';
		vector<int> s(n);
		int cnt = n / 2;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] == 1)
			{
				s[i] = 1;
				--cnt;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			if((cnt > 0) && (s[i] == 0))
			{
				s[i] = 1;
				--cnt;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			cout << s[i];
		}
		cout << '\n';
	}
	else if(zero <= n / 2)
	{
		cout << 0 << '\n';
		vector<int> s(n);
		int cnt = n / 2;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] == 0)
			{
				s[i] = 1;
				--cnt;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			if((cnt > 0) && (s[i] == 0))
			{
				s[i] = 1;
				--cnt;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			cout << s[i];
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

	solve();
	return 0;
}