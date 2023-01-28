#include<bits/stdc++.h>
using namespace std;
#define ll  long long
// #define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << 0 << '\n';
		return ;
	}
	if(n % 2){
		cout << 1 << '\n';
		return ;
	}
	ll t = n & -n;
	ll s = sqrt(t);
	ll p = sqrt(n);
	if(p * p == n){
		cout << 1 << '\n';
		return ;
	}
	if(s * s == t){
		cout << 2 << '\n';
	}else{
		cout << -1 << '\n';
	}
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
}