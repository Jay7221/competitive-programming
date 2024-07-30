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
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<int> h = a;

    auto calc = [&](int ind){
        return max(0, h[ind] - h[ind - 1]);
    };

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += calc(i);
    }
    int mx = *max_element(a.begin(), a.end());

    vector<vector<int>> adj(mx + 10);
    for(int ind = 1; ind <= n; ++ind){
        for(int i = 1; i * i <= a[ind]; ++i){
            adj[i].push_back(ind);
        }
        for(int p = 0; p * p <= a[ind]; ++p){
            int i = a[ind] / (p + 1) + 1;
            adj[i].push_back(ind);
        }
    }


    for(int i = 1; i <= mx; ++i){
        for(int ind: adj[i]){
            cerr << i << '\n';
            cerr << ind << '\n';
            cerr << ans << " : " << h << '\n';
            ans -= calc(ind) + calc(ind + 1);
            h[ind] = a[ind] / i;
            ans += calc(ind) + calc(ind + 1);
            cerr << ans << " : " << h << '\n';
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}
 
