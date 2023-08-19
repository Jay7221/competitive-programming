struct Float{
    ll a, b;

    Float(){
        a = 0, b = 1;
    }

    void operator=(Float x){
        a = x.a;
        b = x.b;
    }
    void operator+=(Float other){
        ll x = other.a;
        ll y = other.b;
        a = (a * y + b * x);
        b = (2 * b * y);
        ll d = gcd(a, b);
        a /= d;
        b /= d;
    }
    void operator-=(Float other){
        ll x = other.a;
        ll y = other.b;
        a = (a * y - b * x);
        b = (2 * b * y);
        ll d = gcd(a, b);
        a /= d;
        b /= d;
    }
    void operator*=(Float other){
        a *= other.a;
        b *= other.b;
        ll d = gcd(a, b);
        a /= d;
        b /= d;
    }
    void operator/=(Float other){
        a *= other.b;
        b *= other.a;
        ll d = gcd(a, b);
        a /= d;
        b /= d;
    }


    template<typename T>
    void operator=(T x){
        a = x;
        b = 1;
    }
    template<typename T>
    void operator+=(T x){
        a += b * x;
    }
    template<typename T>
    void operator-=(T x){
        a -= b * x;
    }
    template<typename T>
    void operator*=(T x){
        a *= x;
    }
    template<typename T>
    void operator/=(T x){
        b *= x;
    }
    friend istream& operator>>(istream& in, Float &m){
        in >> a >> b;
        return in;
    }
    friend ostream& operator<<(ostream& out, Float &m){
        out << a << ' ' << b << '\n';
        return out;
    }
    template<typename T>
    friend Float operator+(Float a, T b){
        Float res = a;
        res += b;
        return res;
    }
    template<typename T>
    friend Float operator-(Float a, T b){
        Float res = a;
        res -= b;
        return res;
    }
    template<typename T>
    friend Float operator*(Float a, T b){
        Float res = a;
        res *= b;
        return res;
    }
};

