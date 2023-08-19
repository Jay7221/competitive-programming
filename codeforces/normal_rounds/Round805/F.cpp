#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	multiset<int> a, b;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		while(k % 2 == 0){
			k /= 2;
		}
		a.insert(k);
	}
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		while(k % 2 == 0){
			k /= 2;
		}
		b.insert(k);
	}
	for(auto c : b){
		if(a.find(c) != a.end()){
			a.erase(a.find(c));
			continue ;
		}
		bool flag = 0;
		while(c){
			c /= 2;
			if(a.find(c) != a.end()){
				a.erase(a.find(c));
				flag = 1;
				break ;
			}	
		}
		if(flag){
			continue ;
		}
		else{
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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