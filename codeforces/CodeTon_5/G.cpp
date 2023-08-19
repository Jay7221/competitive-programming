#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
static const int MAX = 2e5 + 7;
vector<ll> fact, inv, invFact;
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
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
ll divide(ll a, ll b){
    return mult(a, power(b, MOD - 2));
}

template<typename T>
void debug(T arr){
    for(int elem : arr){
        cerr << elem << ' ';
    }
    cerr << '\n';
}

void solve(){
    int n, m, v;
    cin >> n >> m >> v;
    int a[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int dp[n + 1][n + 1];
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i){
        int coeff = divide(mult(i, v), n);
        for(int j = 0; j <= i; ++j){
            if(j < i){
                dp[i][j] = mult(dp[i - 1][j], add(a[i], mult(v, j)));
            }else{
                dp[i][j] = 0;
            }
            if(j > 0){
                dp[i][j] = add(dp[i][j], mult(dp[i - 1][j - 1], mult(coeff, m - j + 1)));
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= n; ++j){
        ans = add(ans, dp[n][j]);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}

