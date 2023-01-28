#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(998244353)
#define debug(a) cerr << (#a) << " : "; for(auto c : a){cerr << c << '\t' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<ll> b(n + 2), pre(n + 2), suf(n + 2), odd(n + 2);
	odd[0] = odd[n + 1] = 0;
	for(int i = 1; i < n + 1; i++)
		cin >> b[i];
	for(int i = 1; i < n + 1; i++)
		odd[i] = (b[i] + 1) / 2;
	pre[0] = 1, suf[n + 1] = 1;
	for(int i = 1; i < n + 1; i++)
		pre[i] = (pre[i - 1] * (b[i] + 1)) % mod;
	for(int i = n; i > 0; i--)
		suf[i] = (suf[i + 1] * (b[i] + 1)) % mod;
	ll ans = 0;
	ans += (((b[1] + 1) / 2) * suf[2]) % mod;
	cerr << ans << ' ';
	for(int i = 2; i < n + 1; i++){
		ans += (((b[i] + 1) / 2) * pre[i - 2] * suf[i + 1]) % mod;
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
}