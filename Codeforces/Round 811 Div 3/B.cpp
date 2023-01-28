#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<bool> vis(n + 1);
	for(int i = n - 1; i > -1; --i){
		if(vis[a[i]]){
			cout << i + 1 << '\n';
			return ;
		}
		vis[a[i]] = 1;
	}
	cout << 0 << '\n';
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