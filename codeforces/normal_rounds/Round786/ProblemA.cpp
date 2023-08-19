#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int x, y;
	cin >>  x >> y;
	if(y % x){
		cout << 0 << ' ' << 0 << '\n';
	}else{
		cout << 1 << ' ' << y / x << '\n';
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