#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[min(k, n - 1)] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}