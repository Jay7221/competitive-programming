#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<bool> flip(n + 2), S(n + 2);
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		S[i + 1] = s[i] - '0';
	}
	// ----------------------------------------------------------------------


	bool cur = 0;
	int tmp = 0;
	for(int i = 1; i <= n - k + 1; ++i){
		cur ^= flip[i];
		if(cur ^ S[i]){
			cur ^= 1;
			flip[i] = flip[i] ^ 1;
			flip[i + k] = flip[i + k] ^ 1;
		}
	}

	for(int i = 1; i < n + 1; ++i){
		flip[i] = flip[i] ^ flip[i - 1];
	}
	for(int i = 1; i <= n; ++i){
		S[i] = S[i] ^ flip[i];
	}




	// ----------------------------------------------------------------------
	for(int i = 1; i <= n; ++i){
		s[i - 1] = S[i] + '0';
	}
	cout << s << '\n';

}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}