#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	if(n % 2 || n < 4){
		cout << -1 << '\n';
		return ;
	}
	ll mx = (n / 4);
	ll mn = (n / 6);
	if(n % 6){
		++mn;
	}
	cout << mn << ' ' << mx << '\n';
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