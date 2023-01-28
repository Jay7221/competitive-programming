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
	set<int> s;
	for(int i = 0; i < n; ++i){
		while(a[i] % 10 != 2 && a[i] % 10 > 0){
			a[i] += a[i] % 10;
		}
	}
	for(int i = 0; i < n; ++i){
		if(a[i] % 10 == 0){
			for(int i = 0; i < n; ++i){
				if(a[i] != a[0]){
					cout << "No\n";
					return ;
				}
			}
			cout << "Yes\n";
			return ;
		}
	}
	for(int i = 1; i < n; ++i){
		if((a[i] - a[0]) % 20){
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
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