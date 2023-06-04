#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1;
	set<char> st;
	while(l < r){
		st.insert(s[l]);
		++l;
		--r;
	}
	if(st.size() > 1){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
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
	
	return 0;
}