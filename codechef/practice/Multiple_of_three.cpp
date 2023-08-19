#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll k;
	int d0, d1;
	cin >> k >> d0 >> d1;
	int d = (d0 + d1) % 10;
	ll ans = 0;
	int block = 0;
	int p = d;
	for(int i = 0; i < 4; i++){
		p = (2 * p) % 10;
		block += p;
	}
	ans += (ll)block * ((k - 3ll) / 4ll);
	ans %= 3;
	ans += (d0 + d1 + d) % 3;
	ans %= 3;
	p = d;
	for(int i = 1; i <= (k - 3) % 4; i++){
		p = (2 * p) % 10;
		ans += p;
	}
	ans %= 3;
	if(ans){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}