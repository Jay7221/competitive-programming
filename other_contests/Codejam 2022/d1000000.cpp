#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx (ll)(1e6)
void solve(){
	ll n;
	cin >> n;
	ll d[n];
	for(ll i = 0; i < n; i++)
		cin >> d[i];
	sort(d, d + n);
	ll cur = 1;
	ll i = 0;
	while(i < n){
		while(i < n && cur > d[i])
			i++;
		if(i < n){
			cur++;
			i++;
		}
	}
	cout << cur - 1;
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << '\n';
	}
}