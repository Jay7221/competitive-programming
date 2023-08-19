#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	map<int, ll> freq;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		++freq[a];
	}
	ll ans = 0;
	for(auto [u, f] : freq){
		ans += f * (n - f);
	}
	ans /= 2;
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