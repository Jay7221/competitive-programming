#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			ans = 1;
			if(i + 1 < n && s[i + 1] == s[i]){
				ans = 2;
				break ;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}