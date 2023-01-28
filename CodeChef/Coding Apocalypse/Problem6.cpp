#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	double n;
	cin >> n;
	double ans = pow(.143 * n, n);
	int ans_1 = ans;
	if(ans - ans_1 > .5){
		cout << ans_1 + 1 << '\n';
	}
	else{
		cout << ans_1 << '\n';
	}
}
int main(){
	fast_io
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}