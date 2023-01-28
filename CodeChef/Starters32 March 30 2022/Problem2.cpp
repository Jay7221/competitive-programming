#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<pair<int, int> > operations;
	bool t = 0;		// is the bit going to be flipped
	for(int i = 0; i < n - 1; i++){
		bool k = s[i] - '0'; 	// should we flip the bit
		if((k && !t) || (!k && t)){
			operations.push_back({i + 1, n - i});
			t ^= 1;
		}
	}
	cout << operations.size() << '\n';
	for(auto c : operations){
		cout << c.first << ' ' << c.second << '\n';
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}