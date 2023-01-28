#include<iostream>
using namespace std;
#define ll long long
void solve(){
	string s;
	cin >> s;
	ll n = s.size();
	ll noflip[n], flip[n], diff[n];
	for(ll i = 0; i < n; ++i){
		noflip[i] = (s[i] - '0') * (((i + 1) * (n - i)));
		flip[i] = ((s[i] - '0') ^ 1) * (((i + 1) * (n - i)));
		diff[i] = flip[i] - noflip[i];
	}
	for(int i = 1; i < n; ++i)
		diff[i] += max(diff[i - 1], 0ll);
	ll ans = 0;
	for(int i = 0; i < n ; ++i)
		ans += noflip[i];
	ll mx = 0;
	for(int i = 0; i < n; ++i)
		mx = max(mx, diff[i]);
	ans += mx;
	cout << ans << '\n';
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