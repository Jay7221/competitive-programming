#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
// ll add(ll a, ll b){
	// return ((a + b) % MOD);
// }
// ll sub(ll a, ll b){
	// return (((a - b) % MOD + MOD) % MOD);
// }
// ll mult(ll a, ll b){
	// return ((a * b) % MOD);
// }
// ll power(ll a, ll p){
	// ll ans = 1, rem = a;
	// while(p > 0){
		// if(p & 1){
			// ans = mult(ans, rem);
		// }
		// rem = mult(rem, rem);
		// p >>= 1;
	// }
	// return ans;
// }
// ll inv(ll a){
	// return power(a, MOD - 2);
// }
// ll divide(ll a, ll b){
	// return mult(a, inv(b));
// }

ll add(ll a, ll b){
	return (a + b);
}
ll mult(ll a, ll b){
	return (a * b);
}
ll divide(ll a, ll b){
	return (a / b);
}
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v[i] = {a[i], i};
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    set<ll> used, unused;
    used.insert(-1);
    used.insert(n);
    for(int i = 0; i < n; ++i){
        unused.insert(i);
    }
    for(auto [x, i] : v){
    	ll l1, l2, r;
    	l1 = *(--used.lower_bound(i));
    	r = *used.upper_bound(i);
    	l2 = -1;
    	if(unused.lower_bound(l1) != unused.begin()){
    		l2 = *(--unused.lower_bound(l1));
    	}
    	
    	ll k = i - l1;
    	ll comp1 = (k * (k - 1)) / 2;
    	ll comp2 = (l1 - l2) * (i - l1 - 1);
    	ll comp3 = (l2 + 1) * (i - l1);
    	ll comp = comp1 + comp2 + comp3;
    	comp *= r - i;
    	ans += comp;
        used.insert(i);
        unused.erase(i);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
