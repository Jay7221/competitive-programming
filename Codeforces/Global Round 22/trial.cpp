#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<bool> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	priority_queue<int> fire, frost;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(v[i])
			fire.push_back(a);
		else
			frost.push_back(a);
	}
	int ans = 0;
	while(firs.size() && frost.size()){
		int a = fire.top(), b = frost.top();
		if(a > b){
			
		}
		else{
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
