#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(int i = 1; i <= n; ++i){cerr << a[i] << ' ' ;}cerr<< '\n';
const ll INF = 1e15 + 7;
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n + 2), pre(n + 2), superpre(n + 2), dp(n + 2);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i - 1] + a[i];
		superpre[i] = superpre[i - 1] + pre[i];
	}
	stack<pair<ll, ll> > st;
	st.push({-INF, n + 1});
	for(int i = n; i >= 0; --i){
		while(st.size() && st.top().first >= pre[i])
			st.pop();
		dp[i + 1] = st.top().second;
		st.push({pre[i], i});
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += (superpre[dp[i] - 1] - superpre[i - 1]) - (dp[i] - i) * pre[i - 1];
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}