#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 2e5 + 7;
template<typename T>
class Modulo{
    T MOD;
    static const int MAX = 2e5 + 7;
    vector<T> fact, inv, invFact;
    public:
        Modulo(T MOD){
            this -> MOD = MOD;

            fact = vector<T>(MAX);
            inv= vector<T>(MAX);
            invFact = vector<T>(MAX);
            fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
            for(int i = 2; i < MAX; ++i){
                T q = MOD / i;
                T r = MOD % i;
                inv[i] = mult(-q, inv[r]);
                fact[i] = mult(i, fact[i - 1]);
                invFact[i] = mult(inv[i], invFact[i - 1]);
            }
        }
        T add(T a, T b){
            a = ((a % MOD) + MOD) % MOD;
            b = ((b % MOD) + MOD) % MOD;
            return ((a + b) % MOD);
        }
        T sub(T a, T b){
            a = ((a % MOD) + MOD) % MOD;
            b = ((b % MOD) + MOD) % MOD;
            return (((a - b) % MOD + MOD) % MOD);
        }
        T mult(T a, T b){
            a = ((a % MOD) + MOD) % MOD;
            b = ((b % MOD) + MOD) % MOD;
            return ((a * b) % MOD);
        }
        T power(T a, T p){
            a = ((a % MOD) + MOD) % MOD;
            T ans = 1;
            while(p > 0){
                if(p & 1){
                    ans = mult(ans, a);
                }
                a = mult(a, a);
                p >>= 1;
            }
            return ans;
        }
        T inverse(T a){
            return power(a, MOD - 2);
        }
        T divide(T a, T b){
            return mult(a, inverse(b));
        }
        T com(T a, T b){
            if(a < b){
                return 0;
            }
            return divide(fact[a], mult(fact[a - b], fact[b]));
        }
};
Modulo<ll> M(998244353);
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0, o = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    g = count(a.begin(), a.end(), 0);
    o = count(a.begin(), a.begin() + g, 0);
    vector<ll> dp(g + 1);
    for(int k = g - 1; k >= 0; --k){
        ll s = M.divide(M.mult(n, n - 1), 2);
        ll p = M.divide(M.mult(g - k, g - k), s);
        dp[k] = M.divide(M.add(1, M.mult(p, dp[k + 1])), p);
    }
    cout << dp[o] << '\n';
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
