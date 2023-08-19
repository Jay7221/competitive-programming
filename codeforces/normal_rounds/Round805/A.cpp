#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll m;
	cin >> m;
	ll k = 1;
	while(10ll * k <= m){
		k *= 10;
	}
	cout << m - k << '\n';
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