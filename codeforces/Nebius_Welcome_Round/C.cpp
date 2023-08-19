#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
ll add(ll a, ll b){
	return ((a + b) % MOD);
}
ll sub(ll a, ll b){
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	return ((a - b + MOD) % MOD);
}
ll mult(ll a, ll b){
	return ((a * b) % MOD);
}
ll get(ll n, ll mod){
	n = (n * (n + 1)) / 2;
	n = n % mod;
	return n;
}
void solve(){
    int n, x, p;
    cin >> n >> x >> p;
    bool flag = false;
    for(int f = 1; f <= min(4 * n, p); ++f){
        ll sum = f * 1ll * (f + 1);
        sum /= 2;
        sum %= n;
        sum += x;
        sum %= n;
        if(sum == 0){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
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
