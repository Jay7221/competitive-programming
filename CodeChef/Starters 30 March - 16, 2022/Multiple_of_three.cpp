#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll k;
	int d0, d1;
	cin >> k >> d0 >> d1;
	int d = (d0 + d1) % 10;
	ll ans = 0;
	int p = d;
	for(int i = 0; i < 4; i++){
		p = (2 * p) % 10;
		ans += p;
	}
	ans %= 3;
	k -= 7;
	ans *= k / 4;
	ans %= 3;
	ans += d + d;
	ans %= 3;
	p = d;
	for(int i = 0; i < k % 4; i++){
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