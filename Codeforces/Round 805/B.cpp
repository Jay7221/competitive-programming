#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n  = s.size();
	int ans = 1;
	int tmp = 0;
	map<char, bool> vis;
	for(int i = 0; i < n; ++i){
		if(!vis[s[i]]){
			if(tmp == 3){
				tmp = 1;
				++ans;
				vis.clear();
				vis[s[i]] = 1;
			}else{
				++tmp;
				vis[s[i]] = 1;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}