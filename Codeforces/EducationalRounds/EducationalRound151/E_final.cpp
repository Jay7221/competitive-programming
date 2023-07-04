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
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

  //  vector<vector<vector<ModInt>>> dp(n, vector<vector<ModInt>>(2 * maxJ, vector<ModInt>(k + 1)));
    maxJ = min(maxJ, k + 1);
    vector<vector<ModInt>> dp(2 * maxJ, vector<ModInt>(k + 1));
    vector<vector<ModInt>> prev(2 * maxJ, vector<ModInt>(k + 1));
    dp[maxJ][0] = 1;
    dp[maxJ + (a[0] ? -1 : 1)][1] = 1;

    auto check = [&](int j){
        return ((j > -maxJ) && (j < maxJ));
    };
    for(int i = 1; i < n; ++i){
        swap(prev, dp);
        for(int j = -maxJ + 1; j < maxJ; ++j){
            for(int kk = 0; kk <= k; ++kk){
                dp[j + maxJ][kk] = 0;
                int jd, kd;

                jd = j + a[i] - 1;
                kd = kk - abs(j);
                if(kd >= 0 && check(jd)){
                    dp[j + maxJ][kk] += prev[jd + maxJ][kd];
                }

                jd = j + a[i];
                kd = kk - abs(j);
                if(kd >= 0 && check(jd)){
                    dp[j + maxJ][kk] += prev[jd + maxJ][kd];
                }
            }
        }
    }

    ModInt ans = 0;
    for(int kk = 0; kk <= k; ++kk){
        if((kk & 1) == (k & 1)){
            ans += dp[maxJ][kk];
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
