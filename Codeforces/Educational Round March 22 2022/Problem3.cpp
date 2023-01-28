#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
bool is_palindrome(string s, int a, int b){
	for(int i = 0; i <= (b - a) / 2; i++){
		if(s[a + i] != s[b - i])
			return 0;
	}
	return 1;
}
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	bool can_proced = 1;
	int brac = 0;
	int j = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			brac++;
		}
		if(s[i] == ')')
			brac--;
		if(brac < 0){
			cerr << i << '\n';
			break ;
		}
		if(brac == 0){
			if(is_palindrome(s, j, i)){
				ans++;
				j = i + 1;
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