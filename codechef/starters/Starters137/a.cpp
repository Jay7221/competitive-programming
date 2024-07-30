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
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    vector<bool> pre1(n, true), pre2(n, true);
    vector<bool> suf1(n, true), suf2(n, true);

    for(int i = 1; i < n; ++i){
        pre1[i] = pre1[i - 1] && (x[i - 1] >= (x[i] - p[i]));
        pre2[i] = pre2[i - 1] && (x[i - 1] + p[i - 1] >= x[i]);
    }
    for(int i = n - 2; i >= 0; --i){
        suf1[i] = suf1[i + 1] && (x[i] + p[i] >= x[i + 1]);
        suf2[i] = suf2[i + 1] && (x[i] >= x[i + 1] - p[i + 1]);
    }

    vector<bool> pre(n), suf(n);
    for(int i = 0; i < n; ++i){
        pre[i] = pre1[i] || pre2[i];
        suf[i] = suf1[i] || suf2[i];
    }


    if(suf[0] || pre[n - 1]){
        return true;
    }
    for(int i = 1; i < n; ++i){
        if(pre[i - 1] && suf[i]){
            return true;
        }
    }

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
