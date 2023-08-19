#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n, m, x, y;
	cin >> n >> m >> x >> y;
	x %= 2, y %= 2;
	if(y == 0){
		if(x == 1){
			cout << "YES\n";
		}else{
			if((n + m) % 2 == 0){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}else{
		if(x == 1){
			if((n + m) % 2 == 1){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}else{
			cout << "YES\n";
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}