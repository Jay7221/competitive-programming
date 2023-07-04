#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ModInt{
    int val;
    const int MOD = 1e9 + 7;

    ModInt(){
        val = 0;
    }

    void operator=(ModInt &x){
        val = x.val;
        val = (val % MOD);
    }
    void operator+=(ModInt &x){
        val = (val + 0ll + x.val) % MOD;
    }
    void operator-=(ModInt x){
        val = (((val + 0ll - x.val) % MOD + MOD) % MOD);
    }
    void operator*=(ModInt x){
        val = (val * 1ll * x.val) % MOD;
    }

    template<typename T>
    ModInt(T x){
        val = x;
    }
    template<typename T>
    void operator=(T x){
        val = x;
        val = (val % MOD);
    }
    template<typename T>
    void operator+=(T x){
        val = (val + 0ll + x) % MOD;
    }
    template<typename T>
    void operator-=(T x){
        val = (((val + 0ll - x) % MOD + MOD) % MOD);
    }
    template<typename T>
    void operator*=(T x){
        val = (val * 1ll * x) % MOD;
    }
    friend istream& operator>>(istream& in, ModInt &m){
        in >> m.val;
        return in;
    }
    friend ostream& operator<<(ostream& out, const ModInt &m){
        out << m.val;
        return out;
    }
    template<typename T>
    friend ModInt operator+(ModInt &a, T b){
        ModInt res = a;
        res += b;
        return res;
    }
    template<typename T>
    friend ModInt operator-(ModInt &a, T b){
        ModInt res = a;
        res -= b;
        return res;
    }
    template<typename T>
    friend ModInt operator*(ModInt &a, T b){
        ModInt res = a;
        res *= b;
        return res;
    }
};
int maxJ = 60;

void debug(vector<ModInt> &arr){
    for(ModInt &elem : arr){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void debug(vector<vector<ModInt>> &matrix){
    for(vector<ModInt> &arr: matrix){
        for(ModInt &elem : arr){
            cerr << elem << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
}
const int MOD = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;

    int a[n];
    vector<int> pos;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pos.push_back(i);
    }

    vector<vector<ModInt>> dp(k + 1, vector<ModInt>(n + 1));
    for(int i = 0; i <= n; ++i){
        dp[0][i] = 1;
    }

    debug(dp);
    for(int p : pos){
        for(int kk = 0; kk <= k; ++kk){
            int kd = 1 + sqrt(kk);
            int l = max(1, p - kd);
            int r = min(n, p + kd);
            for(int j = l; j <= r; ++j){
                dp[kk][j] = dp[kk][j - 1];
                int kd = kk - abs(p - j);
                if(kd >= 0){
                    dp[kk][j] += dp[kd][j - 1];
                }
            }
        }
        debug(dp);
    }

    ModInt ans = 0;
    for(int kk = 0; kk <= k; ++kk){
        if((kk & 1) == (k & 1)){
            ans += dp[kk][n];
        }
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
