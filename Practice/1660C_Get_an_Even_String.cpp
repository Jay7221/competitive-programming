#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string a;
	cin >> a;
	int n = a.size();
	map<char, bool> enc;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(enc[a[i]]){
			enc.clear();
			ans += 2;
		}else{
			enc[a[i]] = 1;
		}
	}
	ans = n - ans;
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
}