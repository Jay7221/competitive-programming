#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s, t;
	cin >> s >> t;
	if(t == "a"){
		cout << 1 << '\n';
		return ;
	}
	for(auto c : t){
		if(c == 'a'){
			cout << -1 << '\n';
			return ;
		}
	}
	ll ans = 1;
	for(auto c : s){
		ans *= 2;
	}
	cout << ans << '\n';
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