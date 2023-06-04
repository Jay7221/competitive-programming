#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n), d1(n), d2(n);
	vector<ll> k(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	k[n - 1] = b[n - 1];
	for(int i = n - 2; i > -1; --i){
		if(a[i + 1] <= b[i]){
			k[i] = k[i + 1];
		}else{
			k[i] = b[i];
		}
	}
	for(int i = 0; i < n; ++i){
		d1[i] = *(lower_bound(b.begin(), b.end(), a[i])) - a[i];
	}
	for(int i = 0; i < n - 1; ++i){
		d2[i] = k[i] - a[i];
	}
	d2[n - 1] = k[n - 1] - a[n - 1];
	for(int i = 0; i < n; ++i)
		cout << d1[i] << ' ' ;
	cout << '\n';
	for(int i = 0; i < n; ++i)
		cout << d2[i] << ' ' ;
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}