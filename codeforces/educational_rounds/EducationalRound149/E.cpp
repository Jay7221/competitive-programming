#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const int MAX = 1e6 + 7;
vector<ll> fact(MAX);
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    ll ans = 1, rem = a;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, rem);
        }
        rem = mult(rem, rem);
        p >>= 1;
    }
    return ans;
}
ll inv(ll a){
    return power(a, MOD - 2);
}
ll divide(ll a, ll b){
    return mult(a, inv(b));
}
void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i){
        fact[i] = mult(i, fact[i - 1]);
    }
}

void solve(){
    int k;
    cin >> k;
    int n = (1 << k);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > 0){
            --a[i];
        }
    }
    ll ans = 1;
    while(k > 0){
        n = (1 << k);

        ll cur = 1;
        ll cnt = 0;

        for(int i = 0; i < n; i += 2){
            int l = i, r = i + 1;
            if((a[l] == -1) && (a[r] == -1)){
                cur = mult(cur, 2);
                ++cnt;
            }
            else if(a[l] == -1){
                if(a[r] < n / 2){
                    ++cnt;
                }
            }
            else if(a[r] == -1){
                if(a[l] < n / 2){
                    ++cnt;
                }
            }
            else{
                if((a[l] < n / 2) && (a[r] < n / 2)){
                    cur = 0;
                    break;
                }
                if((a[l] >= n / 2) && (a[r] >= n / 2)){
                    cur = 0;
                    break;
                }
            }
        }
        cur = mult(cur, fact[cnt]);
        ans = mult(ans, cur);

        for(int i = 0; i < n / 2; ++i){
            int l = 2 * i, r = 2 * i + 1;
            if((a[l] >= 0) && (a[l] < n / 2)){
                a[i] = a[l];
            }else if((a[r] >= 0) && (a[r] < n / 2)){
                a[i] = a[r];
            }else{
                a[i] = -1;
            }
        }
        --k;
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    solve();

    return 0;
}
