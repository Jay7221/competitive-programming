struct ModInt{
    int val;
    const int MOD = 1e9 + 7;

    ModInt(){
        val = 0;
    }

    void operator=(ModInt x){
        val = x.val;
        val = (val % MOD);
    }
    void operator+=(ModInt x){
        val = (val + 0ll + x.val) % MOD;
    }
    void operator-=(ModInt x){
        val = (((val + 0ll - x.val) % MOD + MOD) % MOD);
    }
    void operator*=(ModInt x){
        val = (val * 1ll * x.val) % MOD;
    }
    void operator/=(ModInt x){
        int p = MOD - 2;
        while(p > 0){
            if(p & 1){
                val = (val * 1ll * x.val) % MOD;
            }
            p >>= 1;
            x.val = (x.val * 1ll * x.val) % MOD;
        }
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
    template<typename T>
    void operator/=(T x){
        int p = MOD - 2;
        while(p > 0){
            if(p & 1){
                val = (val * 1ll * x) % MOD;
            }
            p >>= 1;
            x = (x * 1ll * x) % MOD;
        }
    }
    friend istream& operator>>(istream& in, ModInt &m){
        in >> m.val;
        return in;
    }
    friend ostream& operator<<(ostream& out, ModInt &m){
        out << m.val;
        return out;
    }
    template<typename T>
    friend ModInt operator+(ModInt a, T b){
        ModInt res = a;
        res += b;
        return res;
    }
    template<typename T>
    friend ModInt operator-(ModInt a, T b){
        ModInt res = a;
        res -= b;
        return res;
    }
    template<typename T>
    friend ModInt operator*(ModInt a, T b){
        ModInt res = a;
        res *= b;
        return res;
    }
};

