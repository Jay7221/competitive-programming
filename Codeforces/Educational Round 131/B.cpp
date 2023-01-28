#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	cout << 2 << '\n';
	vector<int> v;
	for(int i = 1; i < n + 1; i += 2){
		int cur = i;
		while(cur < n + 1){
			v.push_back(cur);
			cur *= 2;
		}
	}
	for(auto c : v){
		cout << c << ' ';
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