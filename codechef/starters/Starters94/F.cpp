#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Modulo{
    ll MOD;
    static const int MAX = 2e5 + 7;
    vector<ll> fact, inv, invFact;
    public:
        Modulo(ll MOD){
            this -> MOD = MOD;

        }
        void pre(){
            fact = vector<ll>(MAX);
            inv= vector<ll>(MAX);
            invFact = vector<ll>(MAX);
            fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
            for(int i = 2; i < MAX; ++i){
                ll q = MOD / i;
                ll r = MOD % i;
                inv[i] = mult(-q, inv[r]);
                fact[i] = mult(i, fact[i - 1]);
                invFact[i] = mult(inv[i], invFact[i - 1]);
            }
        }
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
            const int pMOD = MOD - 1;
            p = ((p % pMOD) + pMOD) % pMOD;
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
        ll com(ll a, ll b){
            if(a < b){
                return 0;
            }
            return divide(fact[a], mult(fact[a - b], fact[b]));
        }
};
const ll MOD = 998244353;
Modulo M(MOD);
void solve(){
    int n, m;
    cin >> n >> m;
    int com1 = (m > n) ? 0 : M.divide(M.power(2, m), M.power(3, n));
    int com2 = 0;
    int s = (m / 2) + 1;
    int e = min(n, m - 1);
    if(s <= e){
        int d = e - s + 1;
        int num = M.mult(M.mult(M.power(3, m), M.power(4, s)), M.sub(M.power(4, d), M.power(3, d)));
        int den = M.mult(M.power(3, n + 1), M.mult(M.power(2, m), M.power(3, d + s - 1)));
        com2 = M.divide(num, den);
    }
    int ans = M.add(com1, com2);
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
