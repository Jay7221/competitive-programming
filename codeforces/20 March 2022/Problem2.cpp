#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	string s;
	cin >> s;
	n = s.size();
	map<char, int> freq;
	for(int i = 0; i < n ;i++){
		freq[s[i]]++;
	}
	string ans;
	bool is_head = 1;
	for(int i = 0; i < n; i++){
		if(freq[s[i]] > 1 && is_head){
			freq[s[i]]--;
			continue ;
		}
		if(freq[s[i]] > 0){
			ans.push_back(s[i]);
			freq[s[i]]--;
			is_head = 0;
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