#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
	while(b){
		ll temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void solve(){
	ll a, b;
	cin >> a >> b;
	if(a < 2 || b < 2){
		cout << -1 << '\n';
		return ;
	}
	if(gcd(a, b) > 1){
		cout << 0 << '\n';
	}else{
		cout << 1 << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}