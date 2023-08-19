#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	for(int i = 0; i < n; ++i){
		int cnt = 1;
		while((i + 1 < n) && (s[i] == s[i + 1])){
			++i;
			++cnt;
		}
		cnt %= 2;
		if(cnt == 0){
			cnt = 2;
		}
		while(cnt--){
			ans.push_back(s[i]);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
