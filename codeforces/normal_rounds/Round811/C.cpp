#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	set<int> s;
	for(int i = 9; i > 0 && n > 0; --i){
		if(i <= n){
			n -= i;
			s.insert(i);
		}
	}
	for(auto c : s){
		cout << c ;
	}
	cout << '\n';
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