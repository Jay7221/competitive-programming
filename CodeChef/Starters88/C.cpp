#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int A, B, C;
	cin >> A >> B >> C;
	int ans = 1;
	for(int k = 0; k < C; ++k){
		int a = (1 & (A >> k));
		int b = (1 & (B >> k));
		if(a != b){
			ans <<= 1;
		}
	}
	cout << ans << '\n';
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