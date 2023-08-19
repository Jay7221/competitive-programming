#include<bits/stdc++.h>
using namespace std;
void printPerm(vector<int> &v)
{
	for(int elem : v)
	{
		cout << (elem + 1) << ' ';
	}
	cout << '\n';
}
void debugPerm(vector<int> &v)
{
	for(int elem : v)
	{
		cerr << (elem + 1) << ' ';
	}
	cerr << '\n';
}
vector<int> getPerm(vector<int> oldPerm, vector<int> newPerm)
{
	int n = oldPerm.size();
	vector<int> p(n);
	vector<int> oldInd(n), newInd(n);
	for(int i = 0; i < n; ++i)
	{
		oldInd[oldPerm[i]] = i;
		newInd[newPerm[i]] = i;
	}
	for(int i = 0; i < n; ++i)
	{
		p[newInd[i]] = oldInd[i];
		// p[oldInd[i]] = newInd[i];
	}
	return p;
}
vector<int> concat(vector<int> p, vector<int> q)
{
	int n = p.size();
	vector<int> ans(n);
	for(int i = 0; i < n; ++i)
	{
		ans[i] = p[q[i]];
	}
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), p(n), q(n), final(n), mid(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
		p[i] = i;
		final[i] = i;
	}
	auto check = [&]
	{
		for(int i = 0; i < n; ++i)
		{
			if((p[i] == i) || (q[i] == i) || (a[p[q[i]]] != i))
			{
				return false;
			}
		}
		return true;
	};
	if(n > 5)
	{
		int cnt = max(100, n);
		while(cnt--)
		{
			random_shuffle(p.begin(), p.end());
			q = getPerm(concat(a, p), final);
			if(check())
			{
				cout << "Possible\n";
				printPerm(p);
				printPerm(q);
				return ;
			}
		}
	}
	else
	{
		int cnt = 1;
		for(int i = 1; i <= n; ++i)
		{
			cnt *= i;
		}
		while(cnt--)
		{
			next_permutation(p.begin(), p.end());
			q = getPerm(concat(a, p), final);
			if(check())
			{
				cout << "Possible\n";
				printPerm(p);
				printPerm(q);
				return ;
			}
		}
	}
	cout << "Impossible\n";
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