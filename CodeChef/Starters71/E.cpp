#include<bits/stdc++.h>
using namespace std;
int n, m, N;
const int INF = 1e9 + 7;
vector<int> b;
vector<vector<int>> matrix;
template<typename T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		cerr << elem << ' ';
	}
	cerr << '\n';
}
pair<int, int> getIndex()
{
	int k = n + m - 1;
	int front = n / 2, back = (n - 1) / 2;
	int cur = INF;
	int l = front;
	for(int i = front; i + back + k - 1 < N; ++i)
	{
		int tmp = b[i + k - 1] - b[i];
		if(tmp < cur)
		{
			cur = tmp;
			l = i;
		}
	}
	return {l, l + k - 1};
}
void construct(int l, int r)
{
	matrix.assign(n, vector<int>(m, 0));
	int ll = l;
	for(int i = 0; i < n; ++i)
	{
		matrix[i][0] = b[ll];
		++ll;
	}
	for(int j = 1; j < m; ++j)
	{
		matrix[n - 1][j] = b[ll];
		++ll;
	}
	--l, ++r;
	if(m > 1)
	{
		int j = 1;
		for(int i = 0; i < n - 1; i += 2)
		{
			matrix[i][j] = b[l];
			--l;
		}
		for(int i = 1; i < n - 1; i += 2)
		{
			matrix[i][j] = b[r];
			++r;
		}
	}
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = 2; j < m; ++j)
		{
			if(l > -1)
			{
				matrix[i][j] = b[l];
				--l;
			}
			else
			{
				matrix[i][j] = b[r];
				++r;
			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	N = n * m;
	bool flag = true;
	if(n > m)
	{
		swap(n, m);
		flag = false;
	}
	b.assign(N, 0);
	for(int i = 0; i <  N; ++i)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	int l, r;
	tie(l, r) = getIndex();
	construct(l, r);
	if(flag)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else
	{
		for(int j = 0; j < m; ++j)
		{
			for(int i = 0; i < n; ++i)
			{
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
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
		solve();
	}
	return 0;
}