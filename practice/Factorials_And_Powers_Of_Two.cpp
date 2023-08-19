#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<ll> fact(15);
#define inf (int)(1000)
int popc(ll n){
	ll k = 1;
	int ans = 0;
	while(k <= n){
		if(k & n)
			ans++;
		k = (k << 1) ;
	}
	return ans ;
}
void pre(){
	fact[0] = 6;
	for(int i = 1; i < 15; i++)
		fact[i] = fact[i - 1] * (i + 3);
}
int com(ll n){
	int ans = popc(n);
	for(int k = 1; k < (1 << 15); k++){
		ll sum = 0;
		for(int i = 0; i < 15; i++){
			if(k & (1 << i))
				sum += fact[i];
		}
		if(sum <= n){
			if(ans > popc(k) + popc(n - sum)){
				ans = popc(k) + popc(n - sum);
			}
		}
	}
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	cout << com(n) << '\n';
}
int main(){
	pre();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}