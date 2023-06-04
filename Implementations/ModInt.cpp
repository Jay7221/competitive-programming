#include<bits/stdc++.h>
using namespace std;
#define ll long long
class ModInt{
    public:
        ll MOD = 1e9 + 7;
        ll val;
        ModInt(){
            val = 0;
        }
        ModInt(ll val){
            this -> val = val;
        }
        ll power(ll a, ll p){
            ll ans = 1;
            while(p > 0){
                if(p & 1){
                    ans = (ans * a) % MOD;
                }
                p >>= 1;
                a = (a * a) % MOD;
            }
            return ans;
        }
        void operator==(ll x){
            val = x;
            val = ((val % MOD) + MOD) % MOD;
        }
        void operator+=(ll x){
            val = (val + x) % MOD;
        }
        void operator-=(ll x){
            val = ((val - x) % MOD + MOD) % MOD;
        }
        void operator*=(ll x){
            val = (val * x) % MOD;
        }
        void operator/=(ll x){
            val = (val * power(x, MOD - 2)) % MOD;
        }
};
int main(){
    int x;
    cin >> x;
    ModInt m;
    m = x;
    m *= 4;
    m /= 2;
    cout << m.val << '\n';
}
