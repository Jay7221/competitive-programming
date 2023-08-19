#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	string n;
	cin >> n;
	int r = 0;
	for(auto c : n){
		r += c - '0';
		r %= 9;
	}
	r = 9 - r;
	r %= 9;
	char l = r + '0';
	bool inserted = 0;
	if(l == '0'){
		string ins = "0";
		n.insert(1, ins);
		cout << n << '\n';
		return ;
	}
	string ans;
	for(int i = 0; i < n.size(); i++){
		if(!inserted && n[i] > l){
			ans.push_back(l);
			inserted = 1;
		}
		ans.push_back(n[i]);
	}
	if(!inserted){
		ans.push_back(l);
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}