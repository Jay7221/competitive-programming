#include<iostream>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, cur = 0, pre = 0;
	bool isPre = true;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '0')
		{
			if(isPre)
			{
				pre = cur;
			}
			isPre = false;
			cur = 0;
		}
		else
		{
			++cur;
		}
		ans = max(ans, cur + pre);
	}
	cout << ans << '\n';
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