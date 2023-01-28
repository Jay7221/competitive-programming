#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> c(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ll a;
			cin >> a;
			c[i] += a * j;
		}
	}
	ll mn = *min_element(c.begin(), c.end());
	for(int i = 0; i < n; ++i){
		if(c[i] > mn){
			cout << i + 1 << ' ' << c[i] - mn << '\n';
			return ;
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}