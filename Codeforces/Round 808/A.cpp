#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i){
		if(a[i] % a[0]){
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