#include<bits/stdc++.h>
using namespace std;
#define ll __int128
void solve(){
	long long xx, yy;
	cin >> xx >> yy;
	ll x = xx;
	ll y = yy;
	bool flag = true;
	if(y % x != 0){
		flag = false;
	}
	y /= x;
	if(x * x + 4 * y * y != 4 * y * x){
		flag = false;
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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
	
	return 0;
}