#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1; i <= n; ++i){
		s.insert(i);
	}
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		if(s.find(k) != s.end()){
			s.erase(s.find(k));
		}else{
			s.insert(k);
		}
		if(s.size()){
			cout << *(s.begin()) << ' ' << *(--s.end()) << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}