#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
	int n, h, x;
	cin >> n >> h >> x;
	h -= x;
	int t;
	bool can_solve = 0;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t >= h){
			can_solve = 1;
		}
	}
	if(can_solve){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}
int main(){
	fast_io
	int t;
	t = 1;
	while(t--){
		solve();
	}
}