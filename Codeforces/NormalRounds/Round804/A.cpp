#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	if(n & 1ll){
		cout << -1 << '\n';
		return ;
	}else{
		ll a = (n >> 1), b = 0, c = 0;
		cout << a << ' ' <<  b << ' ' << c << '\n';
	}
}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}