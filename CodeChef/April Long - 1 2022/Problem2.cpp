#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll compute(ll N){
	ll beauty = 1;
	if(N % 4 != 1)
		beauty |= 2;
	ll n = 4;
	while(n <= N){
		ll k = (N + 1)  % (2 * n);
		k -= n;
		if(k > 0){
			k = (k + 1) / 2;
			if(k % 2)
			beauty |= n;
		}
		n = n << 1;
	}
	return beauty;
}
ll brute(int n){
	int b = 1;
	for(int i = 2; i < n + 1; i++){
		if(i % 2)
			b &= i;
		else
			b ^= i;
	}
	return b;
}
void solve(){
	ll n;
	cin >> n;
	cout << compute(n) << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}