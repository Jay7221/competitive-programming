#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	auto count = [&](ll n){
		int ans = 0;
		while(n){
			ans += n %10;
			n /= 10;
		}
		return ans;
	};
	int ans = 0;
	for(ll dm = 1; dm <= 200; ++dm){
		if(n % dm)
			continue ;
		if(dm == count(n / dm))
			++ans;
	}
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
	return 0;
}