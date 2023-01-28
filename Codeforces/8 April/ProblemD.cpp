#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int r = 0;
	for(int k = 0; k < 30; k++){
		cout << "? " << ((1 << k) - r) << ' ' << ((1 << k) + (1 << (k + 1)) - r) << '\n';
		cout.flush();
		int gcd;
		cin >> gcd;
		if(gcd == (1 << (k + 1))){
			r += (1 << k);
			continue ;
		}
		if(gcd == (1 << k))
			continue ;
	}
	cout << "! " << r << '\n';
	cout.flush();
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