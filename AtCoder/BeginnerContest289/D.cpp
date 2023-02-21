#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	int x;
	cin >> x;
	vector<bool> isPossible(x + 7), isLocked(x + 7);
	for(int B : b)
	{
		if(B <= x)
		{
			isLocked[B] = true;
		}
	}
	auto check = [&](int ind)
	{
		return ((ind >= 0) && (ind <= x) && (!isLocked[ind]));
	};
	isPossible[0] = true;
	for(int i = 0; i <= x; ++i)
	{
		if(!isPossible[i])
		{
			continue;
		}
		for(int A : a)
		{
			int j = i + A;
			if(check(j))
			{
				isPossible[j] = (isPossible[j] | isPossible[i]);
			}
		}
	}
	if(isPossible[x])
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
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