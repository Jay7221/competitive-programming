#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 5e5 + 7;
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

vector<vector<int>> primes(MAX);
int noCoprimes(int n, int N){
    int ans = 0;
    for(int mask = 0; mask < (1 << primes[n].size()); ++mask){
        int mult = 1;
        for(int i = 0; i < primes[n].size(); ++i){
            if((mask >> i) & 1){
                mult *= -primes[n][i];
            }
        }
        ans += N / mult;
    }
    return ans;
}
void pre(){
    inv[1] = 1;
    for(int i = 2; i < MAX; ++i){
        int q = MOD / i;
        int r = MOD % i;
        inv[i] = mult(q, MOD - inv[r]);
    }
    for(int i = 2; i < MAX; ++i){
        if(primes[i].size() == 0){
            primes[i].push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                primes[i * j].push_back(i);
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> expected(n + 1, 1);
    expected[1] = 0;
    for(int i = 1; i <= n; ++i){
        if(i > 1){
            expected[i] = divide(mult(n, expected[i]), n - (n / i));
        }
        for(int j = 2; i * j <= n; ++j){
            int tmp = divide(mult(noCoprimes(j, n / i), expected[i]), n);
            expected[i * j] = add(expected[i * j], tmp);
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << expected[i] << ' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    solve();

    return 0;
}
