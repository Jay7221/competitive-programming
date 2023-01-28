#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ans = true;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0'){
			continue ;
		}else{
			if(i < n - 1 && s[i + 1] == s[i]){
				++i;
			}else{
				ans = false;
			}
		}
	}
	if(s.size() == 1){
	    ans = true;
	}
	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
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