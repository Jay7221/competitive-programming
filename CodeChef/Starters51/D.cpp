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
	ll x = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] % 2){
			x ^= n - i - 1;
		}
	}
	if(x)
		cout << "Chef\n";
	else
		cout << "Cook\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}