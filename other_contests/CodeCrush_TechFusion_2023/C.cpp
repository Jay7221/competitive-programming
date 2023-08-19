#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	set<tuple<int, int, int>> st;
	for(int i = 0; i < n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		int d = gcd(a, gcd(b, c));
		a /= d;
		b /= d;
		c /= d;
		st.insert({a, b, c});
	}
	map<pair<int, int>, int> freq;
	for(auto [a, b, c] : st){
		++freq[{a, b}];
	}
	int ans = 0;
	for(auto [u, v] : freq){
		ans = max(ans, v);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
