#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		if(s[i] != t[i]){
			flag = 0;
			break ;
		}
	}
	if(flag){
		cout << "YES\n";
		return ;
	}
	if(count(s.begin(), s.end(), '1') == 0){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n - 1; ++i){
		if(t[i] == t[i + 1]){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
	return ;
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