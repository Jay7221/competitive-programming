#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e7 + 7;
const ll MOD = 1e9 + 7;
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
    return mult(a, power(b, MOD - 2));
}
vector<int> val(MAX), nodiv(MAX, 1), pct(MAX);
void pre(){
    vector<bool> isPrime(MAX, true);
    for(int p = 2; p < MAX; ++p){
        if(isPrime[p]){
            ++pct[p];
            ++nodiv[p];
            for(int d = 2; p * d < MAX; ++d){
                isPrime[d * p] = false;
                int a = 1;
                int cur = d;
                while(cur % p == 0){
                    cur /= p;
                    ++a;
                }
                pct[p * d] += a;
                nodiv[p * d] *= a + 1;
            }
        }
    }
    for(int i = 1; i < MAX; ++i){
        val[i] = ((3 * (nodiv[i] - 1)) % MOD + (pct[i] * (nodiv[i] - 2)) % MOD) % MOD;
        --nodiv[i];
    }
    for(int i = 2; i < MAX; ++i){
        val[i] += val[i - 1];
        val[i] %= MOD;
        nodiv[i] += nodiv[i - 1];
        nodiv[i] %= MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << divide(val[n], 2 * nodiv[n]) << '\n';
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

