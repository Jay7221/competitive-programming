#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans;
	if(n < a){
		ans = 0;
	}else{
		ans = (n / a - 1) * min(a, b);
		ans += min(b, n % a + 1);
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
