#include<iostream>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int ans;
	if(s[0] == s[n - 1])
		ans = n - 2;
	else
		ans = 2;
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