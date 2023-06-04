#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, k, b, s;
	cin >> n >> k >> b >> s;
	ll m = s - k * b;
	if(m >= 0ll && m <= n * (k - 1ll)){
		vector<ll> a(n);
		a[0] = k * b;
		for(int i = 0; i < n; ++i){
			a[i] += min(m, k - 1);
			m -= min(m, k - 1);
		}
		for(auto elem : a)
			cout << elem << ' ' ;
		cout << '\n';
	}else{
		cout << -1 << '\n';
	}
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
}