#include<bits/stdc++.h>
using namespace std;
class SegmentTree
{
public:
	int N;
	vector<int> tree;
	SegmentTree(int n)
	{
		N = 1;
		while(N < n)
		{
			N <<= 1;
		}
		tree.assign(2 * N, 1);
		for(int i = N - 1; i > 0; --i)
		{
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	}
	int get(int ind)
	{
		int cur = 1;
		while(cur < N)
		{
			--tree[cur];
			cur <<= 1;
			if(tree[cur] < ind)
			{
				ind = ind - tree[cur];
				++cur;
			}
		}
		--tree[cur];
		return (cur - N);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n), p(n), val(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	SegmentTree tree(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		val[i] = tree.get(p[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[val[i]] << ' ' ;
	}
	return 0;
}