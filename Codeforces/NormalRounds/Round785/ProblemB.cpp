#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	set<char> present;
	map<char, int> freq;
	for(auto c : s){
		present.insert(c);
		freq[c]++;
	}
	int mx_freq = 0, mn_freq = n;
	for(auto c : present){
		mx_freq = max(mx_freq, freq[c]);
		mn_freq = min(mn_freq, freq[c]);
	}
	if(mx_freq - mn_freq > 1){
		cout << "NO\n";
		return ;
	}
	int k = present.size();
	for(int i = 0; i < k; i++){
		for(int j = i + k; j < n; j++){
			if(s[j] != s[j - k]){
				cout << "NO\n";
				return ;
			}
		}
	}
	cout << "YES\n";
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