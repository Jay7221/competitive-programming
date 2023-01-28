#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << 2 << '\n';
		return ;
	}
	ll ans;
	ans = n / 3;
	if(n % 3)
		++ans;
	cout << ans << '\n';

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