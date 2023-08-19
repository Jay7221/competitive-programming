#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	int x;
	cin >> x;
	if(x % 10){
		if(x % 5){
			cout << -1 << '\n';
		}
		else{
			cout << 1 << '\n';
		}
	}
	else{
		cout << 0 << '\n';
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