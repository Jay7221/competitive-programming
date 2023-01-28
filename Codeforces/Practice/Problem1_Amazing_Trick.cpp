#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> decompose(vector<int> &a)
{
	int n = a.size();
	vector<bool> vis(n);
	vector<vector<int>> ans;
	for(int i = 0; i < n; ++i)
	{
		int cur = i;
		vector<int> cycle;
		while(!vis[cur])
		{
			vis[cur] = true;
			cycle.push_back(cur);
			cur = a[cur];
		}
		if(cycle.size())
		{
			ans.push_back(cycle);
		}
	}
	return ans;
}
void debug(vector<int> &arr)
{
	for(auto elem : arr)
	{
		++elem;
		cerr << elem << ' ';
	}
	cerr << '\n';
}
vector<int> generateOdd(vector<int> &arr)
{
	int n = arr.size();
	vector<int> ans(n);
	for(int i = 0, j = 0; i < n; ++i, j = (j + 2) % n)
	{
		ans[j] = arr[i];
	}
	return ans;
}
vector<int> generatePer(vector<vector<int>> &cycles, int n)
{
	vector<int> ans(n);
	for(auto cycle : cycles)
	{
		int m = cycle.size();
		for(int i = 0; i < m; ++i)
		{
			ans[cycle[i]] = cycle[(i + 1) % m];
		}
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		--tmp;
		a[tmp] = i;
		// cin >> a[i];
		// --a[i];
	}
	vector<vector<int>> even, odd;
	for(auto v : decompose(a))
	{
		if(v.size() % 2)
		{
			odd.push_back(v);
		}
		else
		{
			even.push_back(v);
		}
	}
	if(even.size() % 2)
	{
		cout << "Impossible\n";
		return;
	}
	vector<vector<int>> p, q;
	for(auto cycle : odd)
	{
		vector<int> v = generateOdd(cycle);
		debug(cycle);
		debug(v);
		q.push_back(v);
		p.push_back(v);
	}
	for(auto elem : generatePer(p, n))
	{
		++elem;
		cout << elem << ' ';
	}
	cout << '\n';
	for(auto elem : generatePer(q, n))
	{
		++elem;
		cout << elem << ' ';
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