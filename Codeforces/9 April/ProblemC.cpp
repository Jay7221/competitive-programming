#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(ll ones, ll twos){
	if(ones == twos){
		return ones * 2;
	}
	if(ones > twos){
		return ones * 2 -  1;
	}
	if(twos > ones){
		ll k = twos - ones;
		twos -= k / 3;
		if(k % 3 != 2){
			return twos * 2;
		}
		return twos * 2 - 1;
	}
	return 0;
}
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll mx = a[n - 1];
	ll ones = 0, twos = 0, alt_ones = 0, alt_twos = 0;
	for(int i = 0; i < n - 1; i++){
		ll k = mx - a[i];
		twos += k / 2;
		ones += k % 2;
		k++;
		alt_twos += k / 2;
		alt_ones += k % 2;
	}
	cout << min(ans(ones, twos), ans(alt_ones + 1, alt_twos)) << '\n';
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