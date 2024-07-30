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
    vector<int> state(n);
    vector<int> dist(n);
    for(int i = 0; i < n; ++i){
        cin >> state[i];
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> dist[i];
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; ++i){
        if(state[i]){
            if((i > 0) && !state[i - 1]){
                pq.push({dist[i - 1] - dist[i], i - 1});
            }
            if((i < n - 1) && !state[i + 1]){
                pq.push({dist[i] - dist[i + 1], i + 1});
            }
        }
    }

    long long res = 0;
    while(!pq.empty()){
        int u, w;
        tie(w, u) = pq.top();
        pq.pop();

        if(state[u]){
            continue;
        }

        state[u] = true;
        res += -w;

        if((u > 0) && !state[u - 1]){
            pq.push({dist[u - 1] - dist[u], u - 1});
        }
        if((u < n - 1) && !state[u + 1]){
            pq.push({dist[u] - dist[u + 1], u + 1});
        }
    }
    cout << res << '\n';
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
 
