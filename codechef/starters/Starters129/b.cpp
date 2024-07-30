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
 
bool check(vector<int> a, int s){
    int tot_xor = 0;
    int ss = 0;
    for(int elem: a){
        tot_xor ^= elem;
        ss += elem;
    }
    return ((tot_xor == 0) && (ss == s));
}
 
void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    if((n > s) || (n == 1) || (s & 1)){
        cout << -1 << '\n';
        return;
    }
    if(n % 2 == 0){
        a.assign(n, 1);
        a[0] += (s - n) / 2;
        a[1] += (s - n) / 2;
    }
    else if(n == 3){
        int k = 1;
        while((s & k) != k){
            k <<= 1;
        }
        a[1] = k / 2;
        a[2] = k / 2;
        int ss = s - k;
        if(ss == 0){
            cout << -1 << '\n';
            return;
        }
        a[0] += ss / 2;
        a[1] += ss / 2;
    }
    else{
        if(n + 3 > s){
            cout << -1 << '\n';
            return;
        }
        a[0] = 1;
        a[1] = 3;
        a[2] = 2;
        int ss = s - (n + 3);
        for(int i = 3; i < n; ++i){
            a[i] = 1;
        }
        a[3] += ss / 2;
        a[4] += ss / 2;
    }
    assert(check(a, s));

    for(int elem: a){
        cout << elem << ' ';
    }
    cout << '\n';
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
 
