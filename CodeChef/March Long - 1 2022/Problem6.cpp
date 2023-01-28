#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vb vector<bool>
#define debug(a, n) for(int i = 1; i<= n; i++){cerr << a[i] << ' ';}cerr << '\n';
void solve(){
	// Never ever make assumptions about the default values
	// Always declare an vector if you are going to using it
	// You may replace it with an array if it gives time limit exceeded 
	// Else it's a better practice to just go with a vector
	int n;
	cin >> n;
	vb s(n + 1, 0);
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for(int i = 2; i <= n; i += 2){
		s[i] = 0;
	}
	vb b(n + 1, 0);		// beauty of the string
	for(int i = 1; i <= n; i++){
		b[i] = b[i - 1] ^ s[i];
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans << 1) + b[i] ;
		ans %= 998244353;
	}
	cout << ans << '\n';
}
int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}