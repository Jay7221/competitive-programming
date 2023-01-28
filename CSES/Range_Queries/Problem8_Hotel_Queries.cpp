#include<bits/stdc++.h>
using namespace std;
template<typename T>
class SegmentTree
{
public:
	int N;
	vector<T> tree;
	T DEFAULT = 0;
	SegmentTree(vector<T> &arr)
	{
		N = 1;
		while(N < arr.size())
		{
			N <<= 1;
		}
		tree.assign(2 * N, DEFAULT);
		for(int i = 0; i < arr.size(); ++i)
		{
			tree[i + N] = arr[i];
		}
		for(int i = N - 1; i > 0; --i)
		{
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}
	int get(T val)
	{
		int cur = 1;
		if(tree[cur] < val)
		{
			return -1;
		}
		while(cur < N)
		{
			cur <<= 1;
			if(tree[cur] < val)
			{
				++cur;
			}
		}
		return (cur - N);
	}
	void update(int ind, T val)
	{
		ind += N;
		tree[ind] += val;
		ind /= 2;
		while(ind > 0)
		{
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
			ind /= 2;
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> h(n), r(m), hotelNo(m);
	for(int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	SegmentTree<int> tree(h);
	for(int i = 0; i < m; ++i)
	{
		cin >> r[i];
		int ind = tree.get(r[i]);
		if(ind != -1)
		{
			tree.update(ind, -r[i]);
			hotelNo[i] = ind + 1;
		}
	}
	for(int i = 0; i < m; ++i)
	{
		cout << hotelNo[i] << ' ';
	}
	return 0;
}