#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
vector<int> inv(MAX);
int add(int a, int b){
    return ((a + b) % MOD);
}
int sub(int a, int b){
    return (((a - b) % MOD + MOD) % MOD);
}
int mult(ll a, ll b){
    return ((a * b) % MOD);
}
int power(int a, int p){
    int ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
int divide(int a, int b){
    return mult(a, inv[b]);
}
void pre(){
    inv[1] = 1;
    for(int i = 2; i < MAX; ++i){
        int q = MOD / i;
        int r = MOD % i;
        inv[i] = mult(q, MOD - inv[r]);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> dpd(n, vector<int>(n));
    dp[0][n - 1] = 1;
    for(char ch : s){
        for(int l = 0; l < n; ++l){
            for(int r = n - 1; r >= l; --r){
                if(l == r){
                    dpd[l][r] = dp[l][r];
                }else{
                    dpd[l][r] = 0;
                }
                if(ch == 'L'){
                    if(r + 1 >= n){
                        continue;
                    }
                    dpd[l][r] = add(dpd[l][r], dpd[l][r + 1]);
                    dpd[l][r] += divide(dp[l][r + 1], r + 1 - l);
                    dpd[l][r] %= MOD;
                }else{
                    if(l - 1 < 0){
                        continue;
                    }
                    dpd[l][r] = add(dpd[l][r], dpd[l - 1][r]);
                    dpd[l][r] += divide(dp[l - 1][r], r - (l - 1));
                    dpd[l][r] %= MOD;
                }
            }
        }
        swap(dp, dpd);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j < n; ++j){
            sum += a[j];
            sum %= MOD;
            ans = add(ans, mult(dp[i][j], sum));
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
