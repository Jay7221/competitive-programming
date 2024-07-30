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
 
const int MOD = 365;

class ModInt {
private:
    int value;

public:
    ModInt() : value(0) {}
    ModInt(int x) : value(x % MOD) {
        if (value < 0) value += MOD;
    }

    ModInt& operator+=(const ModInt& other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        value = (1LL * value * other.value) % MOD;
        return *this;
    }

    ModInt operator+(const ModInt& other) const {
        ModInt result = *this;
        return result += other;
    }

    ModInt operator-(const ModInt& other) const {
        ModInt result = *this;
        return result -= other;
    }

    ModInt operator*(const ModInt& other) const {
        ModInt result = *this;
        return result *= other;
    }

    ModInt operator-() const {
        return ModInt(0) - *this;
    }

    bool operator==(const ModInt& other) const {
        return value == other.value;
    }

    bool operator!=(const ModInt& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
        return os << x.value;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> month = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    for(int i = 1; i < 12; ++i){
        month[i] += month[i - 1];
    }
    vector<vector<int>> event(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        int d1, m1, d2, m2;
        cin >> d1 >> m1 >> d2 >> m2;
        ModInt t1 = d1, t2 = d2;
        if(m1 > 0){
            t1 += month[m1 - 1];
        }
        if(m2 > 0){
            t2 += month[m2 - 1];
        }
        cerr << t2 - t1 << '\n';

        for(int j = 0; j < m; ++j){
            cin >> event[i][j];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
