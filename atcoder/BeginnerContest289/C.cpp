#include<bits/stdc++.h>
using namespace std;

void inputSet(int &s)
{
	int size;
	cin >> size;
	for(int i = 0; i < size; ++i)
	{
		int a;
		cin >> a;
		--a;
		s = (s | (1 << a));
	}
}
int getSet(vector<int> sets, int mask)
{
	int ans = 0;
	for(int i = 0; i < sets.size(); ++i)
	{
		if((mask >> i) & 1)
		{
			ans = (ans | sets[i]);
		}
	}
	return ans;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> s(m);
	for(int i = 0; i < m; ++i)
	{
		inputSet(s[i]);
	}
	int ans = 0;
	for(int mask = 1; mask < (1 << m); ++mask)
	{
		int ss = getSet(s, mask);
		if(ss + 1 == (1 << n))
		{
			++ans;
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}