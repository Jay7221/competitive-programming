#include<bits/stdc++.h>
using namespace std;
#define ll long long
class SegmentTree
{
	public:
		ll INF = 1e9 + 7;
		int n;
		vector<int> tree;
		SegmentTree(int size)
		{
			n = size * 2;
			tree.assign(2 * n, -INF);
		}
		void update(int ind)
		{
			if(ind < n)
			{
				tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
			}
		}
		void set(int ind, int val)
		{
			ind += n;
			tree[ind] = max(tree[ind], val);
			ind /= 2;
			while(ind > 0)
			{
				update(ind);
				ind /= 2;
			}
		}
		int query(int l, int r)
		{
			l += n, r += n;
			int ans = -INF;
			while(l <= r)
			{
				if(l % 2 == 1)
				{
					ans = max(ans, tree[l]);
					++l;
				}
				if(r % 2 == 0)
				{
					ans = max(ans, tree[r]);
					--r;
				}
				l /= 2;
				r /= 2;
			}
			return ans;
		}
};
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n + 1), p(n + 1);
	vector<int> dp(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		p[i] = a[i] + p[i - 1];
	}
	map<ll, int> ind;
	set<ll> tmp;
	for(ll elem : p)
	{
		tmp.insert(elem);
	}
	int cur = 0;
	for(ll elem : tmp)
	{
		ind[elem] = cur;
		++cur;
	}
	SegmentTree tree(cur);
	tree.set(ind[p[0]], dp[0] - 0);
	for(int i = 1; i <= n; ++i)
	{
		dp[i] = max(dp[i - 1], i + tree.query(0, ind[p[i]]));
		// cerr << p[i] << ' ' << ind[p[i]] << '\n';
		// cerr << tree.query(0, ind[p[i]]) << "\n";
		// cerr << dp[i] << ' ' << i << '\n';
		tree.set(ind[p[i]], dp[i] - i);
	}
	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << '\n';
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