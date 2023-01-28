#include<iostream>
using namespace std;
#define ll long long
void solve(){
	ll n, k;
	cin >> n >> k;
	ll ans = 2 * n * k - k * (2 * k + 1);
	if(k >= n / 2){
		ans = n * (n - 1) / 2;
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