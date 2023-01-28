#include<bits/stdc++.h>
using namespace std;
template<typename T>
class sumSegmentTree
{
public:
	int N;
	vector<T> tree;
	T DEFAULT = 0;
	sumSegmentTree(vector<T> &a)
	{
		N = 1;
		while(N < a.size())
		{
			N <<= 1;
		}
		tree.resize(2 * N, DEFAULT);
		for(int i = 0; i < a.size(); ++i)
		{
			tree[i + N] = a[i];
		}
		for(int i = N - 1; i > 0; --i)
		{
			tree[i] = (tree[2 * i] + tree[2 * i + 1]);
		}
	}
	void update(int ind, T val)
	{
		ind += N;
		tree[ind] = val;
		ind /= 2;
		while(ind > 0)
		{
			tree[ind] = (tree[2 * ind] + tree[2 * ind + 1]);
			ind /= 2;
		}
	}
	T query(int l, int r)
	{
		l += N;
		r += N;
		T ans = DEFAULT;
		while(l <= r)
		{
			if(l % 2 == 1)
			{
				ans = ans + tree[l];
				++l;
			}
			if(r % 2 == 0)
			{
				ans = ans + tree[r];
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
	vector<long long> arr(n + 1), diff(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		diff[i] = arr[i] - arr[i - 1];
	}
	sumSegmentTree<long long> tree(diff);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int a, b;
			long long u;
			cin >> a >> b >> u;
			diff[a] = diff[a] + u;
			tree.update(a, diff[a]);
			if(b + 1 <= n)
			{
				diff[b + 1] = diff[b + 1] - u;
				tree.update(b + 1, diff[b + 1]);
			}
		}
		else
		{
			int k;
			cin >> k;
			cout << tree.query(0, k) << '\n';
		}
	}
	return 0;
}