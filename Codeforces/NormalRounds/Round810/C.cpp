#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(k);
	for(int i = 0; i < k; ++i){
		cin >> a[i];
	}
	vector<ll> columns(k);
	for(int i = 0; i < k;  ++i){
		columns[i] = a[i] / n;
	}
	ll tmp = 0;
	for(auto col : columns){
		if(col > 1){
			tmp += col;
		}
	}
	if(tmp == m){
		cout << "YES\n";
		return ;
	}
	if(tmp > m){
		for(auto col : columns){
			if(col > 2){
				cout << "YES\n";
				return ;
			}
		}
		if(m % 2 == 0){
			cout << "YES\n";
			return ;
		}
	}
	for(int i = 0; i < k;  ++i){
		columns[i] = a[i] / m;
	}
	tmp = 0;
	for(auto col : columns){
		if(col > 1){
			tmp += col;
		}
	}
	if(tmp == n){
		cout << "YES\n";
		return ;
	}
	if(tmp > n){
		for(auto col : columns){
			if(col > 2){
				cout << "YES\n";
				return ;
			}
		}
		if(n % 2 == 0){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
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