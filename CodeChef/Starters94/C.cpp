#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    p = ((p % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l1 = 0;
    int l2 = 0;
    int r1 = count(s.begin(), s.end(), '4');
    int r2 = count(s.begin(), s.end(), '*');
    ll ans = 0;
    for(char ch : s){
        if(ch == '4'){
            --r1;
        }
        if(ch == '*'){
            --r2;
        }
        if(ch == '*'){
            ll com1 = add(mult(l1, power(2, l2)), mult(l2, power(2, l2 - 1)));
            ll com2 = add(mult(r1, power(2, r2)), mult(r2, power(2, r2 - 1)));
            ll com = mult(com1, com2);
            ans = add(ans, com);
        }
        if(ch == '0'){
            ll com1 = add(mult(l1, power(2, l2)), mult(l2, power(2, l2 - 1)));
            ll com2 = add(mult(r1, power(2, r2)), mult(r2, power(2, r2 - 1)));
            ll com = mult(com1, com2);
            ans = add(ans, com);
        }
        if(ch == '4'){
            ++l1;
        }
        if(ch == '*'){
            ++l2;
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
    while(t--){
        solve();
    }

    return 0;
}
