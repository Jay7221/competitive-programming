#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll mx = *max_element(a.begin(), a.end());
	ll no_moves = 0, cur = 0;
	for(int i = 0; i < n; ++i){
		if(cur < a[i]){
			no_moves += a[i] - cur;
			cur = a[i];
		}else{
			cur = min(cur, a[i]);
		}
	}
	if(no_moves == mx){
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