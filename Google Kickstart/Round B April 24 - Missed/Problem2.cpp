#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool is_pal(ll a){
	ll b = a;
	ll c = 0;
	while(b){
		c = c * 10ll + (b % 10);
		b /= 10;
	}
	return c == a;
}
void solve(){
	ll n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			ans += is_pal(i);
			if(n / i != i)
				ans += is_pal(n / i);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}