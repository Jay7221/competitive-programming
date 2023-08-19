#include <bits/stdc++.h>
using namespace std;
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';} cerr << '\n';
#define ll long long
#define vi vector<int>
void solve(){
	int n;
	cin >> n;
	ll ans = 0;
	ll a;
	for(int i = 0; i < n; i++){
		cin >> a;
		ans += a - 1;
	}
	cout << ans + 1 << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}