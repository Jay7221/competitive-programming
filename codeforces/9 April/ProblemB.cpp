#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1 << 15)
int calc(int n){
	if(n == 0)
		return 0;
	int ans = 0;
	while((n << ans) < mod){
		ans++;
	}
	return ans ;
}
void solve(){
	int n; 
	cin >> n;
	int ans = 15;
	for(int i = 0; i < 15; i++){
		int k = n + i;
		ans = min(ans,calc(k & -k) + i);
	}
	cout << ans << ' ';
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