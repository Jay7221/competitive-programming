#include<bits/stdc++.h>
using namespace std;
void solve(){
	string w;
	int p;
	cin >> w >> p;
	int cur  = 0;
	for(auto ch : w){
		cur += ch - 'a' + 1;
	}
	cur -= p;
	vector<pair<int, int> > v;
	int ind = 0;
	for(auto c : w){
		v.push_back({c - 'a' + 1, ind++});
	}
	sort(v.begin(), v.end());
	while(cur > 0){
		int ch, ind; 
		tie(ch, ind) = v.back();
		v.pop_back();
		cur -= ch;
	}
	vector<pair<int, int> > a;
	for(auto c : v){
		int x, y;
		tie(x, y) = c;
		a.push_back({y, x});
	}
	string ans;
	sort(a.begin(), a.end());
	for(auto c : a){
		ans.push_back(c.second - 1 + 'a');
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}