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
 
 
bool solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> b(n), c(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }

    if(b[0] != c[0]){
        return false;
    }
    for(int i = 0; i < n; ++i){
        if(b[i] < c[i]){
            return false;
        }
    }
    for(int i = 1; i < n; ++i){
        if((b[i] != b[i - 1]) && (c[i] != c[i - 1])){
            return false;
        }
        if(b[i] < b[i - 1]){
            return false;
        }
        if(c[i] > c[i - 1]){
            return false;
        }
    }

    vector<int> a(n);
    a[0] = b[0];

    // The least index of an unknown element / leftmost unknown element
    int p = 1;


    for(int i = 1; i < n; ++i){
        if(b[i - 1] != b[i]){
            a[i] = b[i];

            while(p < i){
                a[p] = min(b[p], a[p - 1] + d);
                ++p;
            }
            ++p;
        }
        else if(c[i - 1] != c[i]){
            a[i] = c[i];

            while(p < i){
                a[p] = max(c[p], a[p - 1] - d);
                ++p;
            }
            ++p;
        }
    }
    while(p < n){
        a[p] = a[p - 1];
        ++p;
    }

    for(int i = 1; i < n; ++i){
        if(abs(a[i] - a[i - 1]) > d){
            return false;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << '\n';
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(!solve()){
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
