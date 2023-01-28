#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	ll k;
	cin >> k;
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if(a[0] > k){
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n; i++){
		if(a[lower_bound(a, a + n, a[i] - k) - a] == a[i] - k){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}