#include<bits/stdc++.h>
using namespace std;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve()
{
	int n;
	int d12, d13, d23;
	cin >> n >> d12 >> d23 >> d13;
	int sum = d12 + d13 + d23;
	if((sum > 2 * (n - 1)) || (sum % 2 == 1))
	{
		cout << "NO\n";
		return ;
	}
	int x = (d12 + d13 - d23) / 2;
	int y = (d12 + d23 - d13) / 2;
	int z = (d13 + d23 - d12) / 2;
	if((x < 0) || (y < 0) || (z < 0))
	{
		cout << "NO\n";
		return;
	}
	int mid;
	int cur = 4;
	if(x == 0)
	{
		mid = 1;
	}
	else if(y == 0)
	{
		mid = 2;
	}
	else if(z == 0)
	{
		mid = 3;
	}
	else
	{
		mid = n;
	}
	vector<pair<int, int>> edges;
	auto join = [&](int start, int end, int d)
	{
		if(d < 1)
		{
			return;
		}
		vector<int> v;
		v.push_back(start);
		while(v.size() < d)
		{
			v.push_back(cur);
			++cur;
		}
		v.push_back(end);
		for(int i = 1; i < v.size(); ++i)
		{
			edges.push_back({v[i - 1], v[i]});
		}
	};
	join(1, mid, x);
	join(2, mid, y);
	join(3, mid, z);
	++cur;
	join(cur - 1, mid, n - 1 - x - y - z);
	cout << "YES\n";
	for(auto [u, v] : edges)
	{
		cout << u << ' ' << v << '\n';
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