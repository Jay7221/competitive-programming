#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<vector<int> > f(MAX, vector<int>(26));
	// f[i][c] = the max length of string ending at i, such that it is equal to prefix, and the ending char is c
	while(q--){
		string t;
		cin >> t;
		s += t;
	}
}
int main(){
	solve();
}