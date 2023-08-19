#include<bits/stdc++.h>
using namespace std;
int INF = 1e9 + 7;
bool solve()
{
	int n, m;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	cin >> m;
	vector<int> x(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> x[i];
	}



	for(int i = 0; i < n; ++i)
	{
		if(a[i] < b[i])
		{
			return false;
		}
	}

	vector<int> left(n);
	stack<pair<int, int>> st;
	st.push({INF, n});
	for(int i = n - 1; i > -1; --i)
	{
		while(st.top().first <= b[i])
		{
			st.pop();
		}
		left[i] = st.top().second;
		st.push({b[i], i});
	}

	swap(a, b);
	map<int, int> freq, prev;
	for(int i = 0; i < m; ++i)
	{
		++freq[x[i]];
	}
	for(int i = 0; i < n; ++i)
	{
		if(a[i] == b[i])
		{
			continue ;
		}
		prev[a[i]] = i;
	}
	for(int i = n - 1; i > -1; --i)
	{
		if(a[i] == b[i])
		{
			continue ;
		}
		if(prev[a[i]] == i)
		{
			--freq[a[i]];
		}
		else
		{
			if(left[i] < prev[a[i]])
			{
				--freq[a[i]];
			}
			prev[a[i]] = i;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		if(freq[a[i]] < 0)
		{
			return false;
		}
	}
	return true;
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
		if(solve())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}