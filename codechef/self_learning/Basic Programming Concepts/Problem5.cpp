#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
	ll u, v, a, s;
	cin >> u >> v >> a >> s;
	ll k = u * u - 2 * a * s;
	ll t = v * v;
	if(k > t){
		cout << "NO" << "\n";
	}
	else{
		cout << "YES" << "\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}