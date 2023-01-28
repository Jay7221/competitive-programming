#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll l, r;
	cin >> l >> r;
	if(l % 4ll == 0ll){
		cout << l << ' ' << l + 1ll << ' ' << l + 2ll << ' ' << l + 3ll << '\n';
		return ;
	}
	else if(l % 4ll == 2ll){
		cout << l <<  ' '  << l + 1ll << ' ' << l + 2ll << ' ' << l + 3ll << '\n';
		return ;
	}else{
		if(r - l + 1 == 4){
			cout << -1 << '\n';
			return ;
		}
		cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << ' ' << l + 4 << '\n';
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