#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' '; } cerr << '\n';
void solve(){
	int n;
	cin >> n;
	unordered_map<string, int> freq;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		freq[s]++;
	}
	int ans = 0;
	for(auto c : freq){
		ans = max(ans, c.second);
	}
	cout << ans << '\n';
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}