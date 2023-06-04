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
        T divide(T a, T b){
            return mult(a, inv[b]);
        }
        T com(T a, T b){
            if(a < b){
                return 0;
            }
            return divide(fact[a], mult(fact[a - b], fact[b]));
        }
};
