#include<bits/stdc++.h>
using namespace std;
#define ll long long
void debug(vector<ll> &arr){
	for(int i = 1; i < arr.size() - 1; ++i){
		cerr << arr[i] << ' ';
	}
	cerr << '\n';
}
void solve()
{
	const ll MAX = 1e7 + 7;
	const ll INF = 1e15 + 7;
	int n;
	cin >> n;
	vector<ll> h(n + 2), l(n + 1, 0), r(n + 1, n + 1), pre(n + 2);
	

	h[0] = h[n + 1] = -MAX;
	for(int i = 1; i <= n; ++i){
		cin >> h[i];
		pre[i] = h[i] + pre[i - 1];
	}
	pre[n + 1] = h[n + 1] + pre[n];
	

	auto sum = [&](int l, int r){
		return (pre[r] - pre[l - 1]);
	};
	auto add = [&](ll l, ll r){
		return (((l + r) * (r - l + 1)) / 2);
	};
	

	stack<ll> st;
	st.push(0);
	for(int i = 1; i <= n; ++i){
		while(st.size()){
			int j = st.top();
			if( h[j] - j <= h[i] - i ){
				break;
			}
			st.pop();
		}
		l[i] = st.top();
		st.push(i);
	}
	while(st.size()){
		st.pop();
	}
	st.push(n + 1);
	for(int i = n; i > 0; --i){
		while(st.size()){
			int j = st.top();
			if( h[j] + j <= h[i] + i ){
				break;
			}
			st.pop();
		}
		r[i] = st.top();
		st.push(i);
	}
	


	vector<ll> dp1(n + 2), dp2(n + 2);
	for(int i = 1; i <= n; ++i){
		int j = l[i];
		int L = max(0ll, h[i] - (i - (j + 1)));
		dp1[i] = dp1[j] + sum(j + 1, i) - add(L, h[i]);
	}
	for(int i = n; i > 0; --i){
		int j = r[i];
		int L = max(0ll, h[i] - ((j - 1) - i));
		dp2[i] = dp2[j] + sum(i, j - 1) - add(L, h[i]);
	}
	




	ll ans = INF;
	for(int i = 1; i <= n; ++i){
		ans = min(ans, dp1[i] + dp2[i] + h[i]);
	}
	cout << ans << '\n';
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
