#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll x, y;
	cin >> x >> y;
	vector<int> a;
	int cur = x;
	while(cur >= y)
	{
		a.push_back(cur);
		--cur;
	}
	cur += 2;
	while(cur < x)
	{
		a.push_back(cur);
		++cur;
	}
	cout << a.size() << '\n';
	for(int elem : a)
	{
		cout << elem << ' ' ;
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