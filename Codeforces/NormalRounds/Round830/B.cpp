#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool cur = false;
	int ans = 0;
	for(int i = 0; i < n - 1; ++i){
		if(s[i] == '1' && s[i + 1] == '0'){
			if(!cur){
				++ans;
				cur ^= 1;
			}
		}else if(s[i] == '0' && s[i + 1] == '1'){
			if(cur){
				++ans;
				cur ^= 1;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}