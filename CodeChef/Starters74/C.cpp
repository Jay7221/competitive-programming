#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n), left(n), right(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	stack<ll> st;
	st.push(INF);
	for(int i = 0; i < n; ++i)
	{
		while(st.top() < a[i])
		{
			st.pop();
		}
		left[i] = st.top();
		st.push(a[i]);
	}
	while(st.size())
	{
		st.pop();
	}
	st.push(INF);
	for(int i = n - 1; i >= 0; --i)
	{
		while(st.top() < a[i])
		{
			st.pop();
		}
		right[i] = st.top();
		st.push(a[i]);
	}
	set<ll> s;
	for(int i = 0; i < n; ++i)
	{
		if(left[i] != INF)
		{
			s.insert(left[i] - a[i]);
		}
		if(right[i] != INF)
		{
			s.insert(right[i] - a[i]);
		}
	}
	cout << s.size() << '\n';
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