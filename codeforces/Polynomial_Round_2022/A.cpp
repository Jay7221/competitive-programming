#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	string a, s;
	cin >> a;
	int cur = (a[0] - '0');
	for(int i = 1; i < n; ++i)
	{
		if(a[i] == '0')
		{
			s.push_back('+');
		}
		else
		{
			if(cur <= 0)
			{
				++cur;
				s.push_back('+');
			}
			else
			{
				--cur;
				s.push_back('-');
			}
		}
	}
	cout << s << '\n';
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