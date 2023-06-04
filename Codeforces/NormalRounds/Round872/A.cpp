#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool checkPal(string s, int l, int r){
	while(l < r){
		if(s[l] != s[r]){
			return false;
		}
		++l;
		--r;
	}
	return true;
}
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = n - 1;
	if(checkPal(s, 0, n - 2)){
		ans = -1;
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