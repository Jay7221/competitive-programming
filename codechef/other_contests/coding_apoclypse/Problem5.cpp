#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	int x, y;
	cin >> x >> y;
	if(x == y){
		cout << 2 * x - 1 << '\n';
	}
	else{
		cout << x + y << '\n';
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