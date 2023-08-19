#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define ll long long
const ll MOD = 998244353 ;
const ll INF = 1e9 + 7;
void solve(){
	auto add = [&](ll a, ll b){
		return ((a + b) % MOD);
	};
	auto sub = [&](ll a, ll b){
		return ((a - b + MOD) % MOD);
	};
	int n;
	cin >> n;
	vector<int> a(n + 1, INF);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> left(n + 1);
	// left[i] = max index j, such that j < i and a[j] > a[i]
	map<ll, int> ind;
	for(int i = 0; i <= n; ++i)
		ind[a[i]] = i;
	stack<ll> st;
	st.push(a[0]);
	for(int i = 1; i <= n; ++i){
		while(st.top() < a[i])
			st.pop();
		left[i] = ind[st.top()];
		st.push(a[i]);
	}
	vector<ll> dp1(n + 1), dp2(n + 1);
	dp1[1] = 1;
	for(int i = 2; i <= n; ++i){
		dp1[i] = add(dp1[i - 1], dp2[i - 1]);
		if(a[i] > a[i - 1])
			dp1[i] = add(dp1[i], dp1[i - 1]);
		dp2[i] = add(dp1[left[i]], dp2[left[i]]);
	}
	cout << add(dp1[n], dp2[n]) << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}