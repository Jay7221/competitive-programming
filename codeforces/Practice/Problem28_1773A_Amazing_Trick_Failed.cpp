#include<bits/stdc++.h>
using namespace std;
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
	cout << '\n';
}
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), shift(n);
	vector<bool> vis(n, false);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
		shift[a[i]] = (i - a[i] + n) % n;
		vis[shift[a[i]]] = true;
	}
	int k = -1;
	for(int i = 1; i < n; ++i)
	{
		if(!vis[i])
		{
			k = i;
			break;
		}
	}
	// if(k == -1)
	// {
	// 	cout << "Impossible\n";
	// 	return ;
	// }
	vector<int> newPerm = a;
	int tries = 10 * n;
	auto check = [&]()
	{
		for(int i = 0; i < n; ++i)
		{
			if((newPerm[i] == i) or (newPerm[i] == a[i]))
			{
				return false;
			}
		}
		return true;
	};
	while(!check())
	{
		--tries;
		if(tries < 0)
		{
			cout << "Impossible\n";
			return ;
		}
		random_shuffle(newPerm.begin(), newPerm.end());
	}
	cout << "Possible\n";
	vector<int> p = getPerm(a, newPerm);
	vector<int> final(n);
	for(int i = 0; i < n; ++i)
	{
		final[i] = i;
	}
	vector<int> q = getPerm(newPerm, final);
	printPerm(p);
	printPerm(q);
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