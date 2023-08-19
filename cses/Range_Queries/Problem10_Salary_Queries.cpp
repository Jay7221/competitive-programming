#include<bits/stdc++.h>
using namespace std;
class SegmentTree
{
	public:
		int N;
		vector<int> tree;
		vector<int> bucketFreq;
		map<int, int> freq;
		int mx = 1e7, mn = 100;
		SegmentTree(vector<int> &arr)
		{
			N = mx;
			tree.assign(2 * N, 0);
			for(int elem : arr)
			{
				++freq[elem];
				++tree[elem / mn + N];
			}
			for(int i = N - 1; i > 0; --i)
			{
				tree[i] = tree[2 * i] + tree[2 * i + 1];
			}
		}
		void update(int i)
		{
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
		void add(int a)
		{
			++freq[a];
			int bucketA = getBucket(a);
			bucketA += N;
			++tree[bucketA];
			while(bucketA > 1)
			{
				bucketA /= 2;
				update(bucketA);
			}
		}
		void rem(int a)
		{
			--freq[a];
			int bucketA = getBucket(a);
			bucketA += N;
			--tree[bucketA];
			while(bucketA > 1)
			{
				bucketA /= 2;
				update(bucketA);
			}
		}
		int getBucket(int n)
		{
			return n / mn;
		}
		int query(int a, int b)
		{
			int ba = getBucket(a), bb = getBucket(b);
			int ans = queryBucket(ba, bb);
			for(int i = a - 1; getBucket(a) == getBucket(i); --i)
			{
				ans -= freq[i];
			}
			for(int i = b + 1; getBucket(b) == getBucket(i); ++i)
			{
				ans -= freq[i];
			}
			return ans;
		}
		int queryBucket(int ba, int bb)
		{
			int ans = 0;
			int l = ba + N, r = bb + N;
			while((l <= r))
			{
				if((l % 2 == 1))
				{
					ans += tree[l];
					++l;
				}
				if(r % 2 == 0)
				{
					ans += tree[r];
					--r;
				}
				l /= 2;
				r /= 2;
			}
			return ans;
		}
		void update(int a, int b)
		{
			rem(a);
			add(b);
		}
};
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	SegmentTree tree(p);
	for(int i = 0; i < m; ++i)
	{
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		if(ch == '!')
		{
			tree.rem(p[x - 1]);
			p[x - 1] = y;
			tree.add(p[x - 1]);
		}
		else
		{
			cout << tree.query(x, y) << '\n';
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}