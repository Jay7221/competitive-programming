#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 1e15 + 7;
class MaxSegTree
{
public:
	int N;
	vector<ll> tree;
	MaxSegTree(vector<ll> &arr)
	{
		int n = arr.size();
		N = 1;
		while(N < n)
		{
			N <<= 1;
		}
		tree.resize(2 * N);
		for(int i = 0; i < n; ++i)
		{
			tree[N + i] = arr[i];
		}
		for(int i = N - 1; i > 0; --i)
		{
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}
	ll getMax(int l, int r)
	{
		l += N;
		r += N;
		ll ans = -INF;
		while(l <= r)
		{
			if(l & 1)
			{
				ans = max(ans, tree[l]);
				++l;
			}
			if(!(r & 1))
			{
				ans = max(ans, tree[r]);
				--r;
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}
};
void solve1()
{
	int n;
	cin >> n;
	vector<ll> a(n + 2, INF), pre(n + 2, 0), suf(n + 2, 0), l(n + 2), r(n + 2);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i = n; i > 0; --i)
	{
		suf[i] = a[i] + suf[i + 1];
	}
	MaxSegTree preTree(pre), sufTree(suf);
	stack<pair<ll, int>> st;
	st.push({a[0], 0});
	for(int i = 1; i <= n; ++i)
	{
		while(st.top().first <= a[i])
		{
			st.pop();
		}
		l[i] = st.top().second;
		++l[i];
		st.push({a[i], i});
	}
	st.push({INF, n + 1});
	for(int i = n; i > 0; --i)
	{
		while(st.top().first <= a[i])
		{
			st.pop();
		}
		r[i] = st.top().second;
		--r[i];
		st.push({a[i], i});
	}
	bool flag = true;
	for(int i = 1; i <= n; ++i)
	{
		ll left = sufTree.getMax(l[i], i) - suf[i + 1];
		ll right = preTree.getMax(i, r[i]) - pre[i - 1];
		if(a[i] < max(left, right))
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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
		solve1();
	}
	return 0;
}