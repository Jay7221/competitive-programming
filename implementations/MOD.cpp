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
            return mult(a, inv[b]);
        }
        ll com(ll a, ll b){
            if(a < b){
                return 0;
            }
            return divide(fact[a], mult(fact[a - b], fact[b]));
        }
};
