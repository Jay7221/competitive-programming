#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll x;
	cin >> x;
	if(x == 1){
		cout << -1 << '\n';
		return;
	}
	ll a, b, c;
	if(x > 1e6){
		a = 1e6;
		b = x / a;
		c = x % a;
		if(c == 0){
			c += b;
			--a;
		}
	}else{
		a = x - 1;
		b = 1;
		c = 1;
	}
	cout << a << ' ' << b << ' ' << c << '\n';
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