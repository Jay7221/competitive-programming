#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MinimumSegmentTree
{
public:
	int N;
	int INF = 1e9 + 7;
	vector<T> tree;
	MinimumSegmentTree(vector<T> &a)
	{
		N = 1;
		while(N < a.size())
		{
			N <<= 1;
		}
		tree.assign(2 * N, INF);
		for(int i = 0; i < a.size(); ++i)
		{
			tree[i + N] = a[i];		
		}
		for(int i = N - 1; i > 0; --i)
		{
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}
	void update(int ind, T val)
	{
		ind += N;
		tree[ind] = val;
		ind /= 2;
		while(ind > 0)
		{
			tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
			ind /= 2;
		}
	}
	int query(int l, int r)
	{
		l += N;
		r += N;
		int ans = INF;
		while(l <= r)
		{
			if(l % 2 == 1)
			{
				ans = min(ans, tree[l]);
				++l;
			}
			if(r % 2 == 0)
			{
				ans = min(ans, tree[r]);
				--r;
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	MinimumSegmentTree<int> tree(a);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int ind, val;
			cin >> ind >> val;
			--ind;
			tree.update(ind, val);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			--a, --b;
			cout << tree.query(a, b) << '\n';
		}
	}
	return 0;
}