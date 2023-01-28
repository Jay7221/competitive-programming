#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x = a * d, y = b * c;
	// cerr << a << ' ' << b << ' ' << c << ' ' <<  d<< " : " << x << ' ' << y << '\n';
	if(x == y){
		cout << 0 << '\n';
		return ;
	}
	d = gcd(x, y);
	x /= d, y /= d;
	if(x == 1 && y == 1){
		cout << 0 << '\n';
	}else if(x == 1 || y == 1){
		cout << 1 << '\n';
	}else{
		cout << 2 << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}