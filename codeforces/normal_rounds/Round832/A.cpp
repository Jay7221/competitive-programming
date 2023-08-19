#include<iostream>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll a;
		cin >> a;
		ans += a;
	}
	cout << abs(ans) << '\n';
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