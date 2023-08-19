#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map<char, char> mp;
	for(char c = 'a'; c <= 'z'; c++){
		mp[c] = c;
	}
	for(auto c : s){
		char tmp = c;
		c = mp[c];
		while(c != 'a' && k > 0){
			k--;
			c = mp[c - 1];
		}
		for(char i = c; i <= tmp; i++)
			mp[i] = c;
	}
	for(auto &c : s)
		c = mp[c];
	cout << s << '\n';
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
}