#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(2 * n);
	for(int i = 0; i < 2 * n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; ++i){
		if(a[i + n] - a[i] < x){
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