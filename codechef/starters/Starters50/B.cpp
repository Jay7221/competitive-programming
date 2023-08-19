#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll x, y;
	cin >> x >> y;
	ll l = x / 2, r = x / 2 + x % 2;
	for(int i = 1; i <= min((ll)(sqrt(y)), l - 1); ++i){
		if(y % i == 0){
			if(y / i < l){
				cout << l << ' ' << r << '\n';
				cout << i << ' ' << y / i << '\n';
				return ;
			}
		}
	}
	for(int i = r + 1; i <= sqrt(y); ++i){
		if(y % i == 0){
			if(y / i > r){
				cout << l << ' ' << r << '\n';
				cout << i << ' ' << y / i << '\n';
				return ;
			}
		}
	}
	cout << -1 << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}