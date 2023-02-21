#include<bits/stdc++.h>
using namespace std;
#define ll long long
void merge(vector<int>* &v1, vector<int>* &v2)
{
	if(v1 == v2)
	{
		return;
	}
	if((v1 -> size()) < (v2 -> size()))
	{
		swap(v1, v2);
	}
	for(int elem : *v2)
	{
		v1 -> push_back(elem);
	}
	v2 -> clear();
}
void solve()
{
	int MAX = 5e5 + 7;
	vector<vector<int>*> indices(MAX);
	for(int i = 0; i < MAX; ++i)
	{
		indices[i] = new vector<int>();
	}
	int q;
	cin >> q;
	int k = 0;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int x;
			cin >> x;
			indices[x] -> push_back(k);
			++k;
		}
		else
		{
			int x, y;
			cin >> x >> y;
			merge(indices[y], indices[x]);
		}
	}
	vector<int> a(k);
	for(int x = 0; x < MAX; ++x)
	{
		for(int index : *indices[x])
		{
			a[index] = x;
		}
	}
	for(int i = 0; i < k; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
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
