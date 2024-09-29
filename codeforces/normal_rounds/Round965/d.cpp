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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        edges[i] = {l, r};
    }

    sort(edges.begin(), edges.end());

    vector<int> pre(n + 2);
    vector<int> cost(n + 2);

    for(int i = 1; i <= n; ++i){
        cost[i] = i;
    }
    auto set = [&](int l, int r){
        if(l > r){
            return;
        }
        ++pre[l];
        --pre[r + 1];
    };

    int i = 0;
    for(auto [l, r]: edges){
        while(i < l){
            cost[i + 1] = min(cost[i] + 1, cost[i + 1]);
            ++i;
        }
        cost[r] = min(cost[r], cost[l] + 1);
        set(l + 1, r - cost[r]);
    }

    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    for(int i = 1; i < n; ++i){
        if(pre[i] == 0){
            cout << 1;
        }
        else{
            cout << 0;
        }
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
 
