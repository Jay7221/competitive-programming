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
 
 
const ll INF = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> x(k), y(k);
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            ++x[i % k];
        }
        else{
            ++y[i % k];
        }
    }

    auto getCost0 = [&](int ind){
        if(y[ind] % 2 == 0){
            return (y[ind] / 2);
        }
        return (y[ind] / 2 + 2);
    };
    auto getCost1 = [&](int ind){
        if(y[ind] == 0){
            return INF;
        }
        return x[ind];
    };

    ll ans0 = 0, ans1 = 0;
    for(int i = 0; i < k; ++i){
        ans0 += getCost0(i);
        ans1 += getCost1(i);
    }
    cout << min(ans0, ans1) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
