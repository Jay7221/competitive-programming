#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
bool is_interesting(ll n){
	ll prod = 1;
	ll sum = 0;
	int t;
	while(n > 0){
		t = n % 10ll;
		n /= 10ll;
		prod *= t;
		sum += t;
	}
	bool ans = 1;
	if(prod % sum)	ans = 0;
	return ans;
}
void solve(){
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	for(ll i = a; i <= b; i++){
		if(is_interesting(i)){
			ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}