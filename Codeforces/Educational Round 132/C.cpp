#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin >> s;
	int b = 0, q = 0;
	for(auto c : s){
		if(c == '?'){
			++q;
		}else if(c == ')'){
			--b;
		}else{
			++b;
		}
		if(b + q == 1){
			q = 0, b = 1;
		}
	}
	if(b == q){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
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