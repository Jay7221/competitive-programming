#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll a, b;
	cin >> a >> b;
	if(b == 1){
		cout << "YES\n";
		return ;
	}
	ll k = gcd(a, b);
	while(gcd(b, k) > 1){
		k = gcd(b, k);
		while(b % k == 0)
			b /= k;
	}
	if(b != 1)
		cout << "NO\n";
	else
		cout << "YES\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}