#include<bits/stdc++.h>
using namespace std;
#define ll long long
class SegmentTree
{
	public:
		int N;
		vector<ll> tree;
		SegmentTree(vector<int> &a)
		{
			N = 1;
			while(N < a.size())
			{
				N *= 2;
			}
			tree.assign(2 * N, 0);
			for(int i = 0; i < a.size(); ++i)
			{
				tree[N + i] = a[i];
			}
			for(int i = N - 1; i > 0; --i)
			{
				tree[i] = tree[2 * i] + tree[2 * i + 1];
			}
		}
		void update(int ind, int val)
		{
			ind += N;
			tree[ind] = val;
			ind >>= 1;
			while(ind > 0)
			{
				tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
				ind >>= 1;
			}
		}
		ll query(int l, int r)
		{
			l += N;
			r += N;
			ll ans = 0;
			while(l <= r)
			{
				if((l % 2) == 1)
				{
					ans += tree[l];
					++l;
				}
				if((r % 2) == 0)
				{
					ans += tree[r];
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
	for(auto &elem : a)
	{
		cin >> elem;
	}
	SegmentTree tree(a);
	while(q--)
	{
		int type;
		cin >> type;
		int a, b;
		cin >> a >> b;
		if(type == 1)
		{
			--a;
			tree.update(a, b);
		}
		else
		{
			--a, --b;
			cout << tree.query(a, b) << '\n';
		}
	}
}