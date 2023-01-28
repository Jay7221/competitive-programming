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
int sum(vector<int> &arr)
{
	int ans = 0;
	for(auto elem : arr)
	{
		ans += elem;
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	int m = n;
	vector<int> arr(n), a, b;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	a = arr;
	int noZero = 0;
	while(--m)
	{
		b.assign(m, 0);
		for(int i = 0; i < m; ++i)
		{
			b[i] = a[i + 1] - a[i];
		}
		if(noZero > 0)
		{
			b.push_back(a[0]);
			--noZero;
		}
		sort(b.rbegin(), b.rend());
		while((b.size() > 1) && (b.back() == 0))
		{
			b.pop_back();
			++noZero;
		}
		a = b;
		reverse(a.begin(), a.end());
		m = a.size();
	}
	cout << a[0] << '\n';
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