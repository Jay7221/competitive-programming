#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	vector<bool> b(n);
	vector<pair<ll, ll> > p;
	map<ll, ll> freq;
	for(ll i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(auto c : a){
		++freq[c];
	}
	for(int i = 0; i < n; ++i){
		--freq[a[i]];
		if(a[i] <= q){
			b[i] = 1;
		}else{
			if(freq[q] == 0){
				b[i] = 1;
				--q;
			}
		}
	}
	for(auto c : b){
		cout << c;
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