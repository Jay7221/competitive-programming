#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
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
    bool operator>(Float other){
        return ((a * other.b) > (b * other.a));
    }
    bool operator<(Float other){
        return ((a * other.b) < (b * other.a));
    }
    bool operator>=(Float other){
        return ((a * other.b) >= (b * other.a));
    }
    bool operator<=(Float other){
        return ((a * other.b) <= (b * other.a));
    }
    bool operator==(Float other){
        return ((a * other.b) == (b * other.a));
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
        in >> m.a >> m.b;
        return in;
    }
    friend ostream& operator<<(ostream& out, Float &m){
        out << m.a << ' ' << m.b;
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
    template<typename T>
    friend Float operator/(Float a, T b){
        Float res = a;
        res /= b;
        return res;
    }
};
 void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int L = -1, R = -1;
    auto check = [&](Float x){
        vector<Float> p(n);
        for(int i = 0; i < n; ++i){
            p[i] = a[i];
            p[i] -= x;
            if(i > 0){
                p[i] += p[i - 1];
            }
        }
        vector<Float> mn(n);
        vector<int> l(n);
        for(int i = 0; i < n; ++i){
            l[i] = i;
            mn[i] = p[i];
            if(i > 0){
                p[i] += p[i - 1];
                if(mn[i] > mn[i - 1]){
                    l[i] = l[i - 1];
                    mn[i] = mn[i - 1];
                }
            }
        }
        Float z;
        z = 0;
        if(mn[d - 1] >= z){
            L = 0;
            R = d - 1;
            return true;
        }
        for(int i = d; i < n; ++i){
            if(p[i] >= mn[i - d]){
                L = l[i - d] + 1;
                R = i;
                return true;
            }
        }

        return false;
    };
    Float l, r;
    l = 0;
    r = 100;
    for(int cnt = 0; cnt < 30; ++cnt){
        Float mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    ++L;
    ++R;
    cout << L << ' ' << R << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
