#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		sum += a;
	}
	int ans = 0;
	ans = (-1 + sqrt(1 + 8 * sum)) / 2;
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}