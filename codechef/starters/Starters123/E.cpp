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
    vector<vector<int>> adj(n);
    vector<int> neighbours(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char ch;
            cin >> ch;
            if(ch == '1'){
                adj[i].push_back(j);
                neighbours[i] |= (1 << j);
            }
        }
    }

    int ans = n;

    const int MAX_MASK = (1 << n) - 1;


    auto check = [&](int leaves){
        int not_leaves = leaves ^ MAX_MASK;
        vector<int> nodes;
        for(int i = 0; i < n; ++i){
            if(1 & (leaves >> i)){
                if((neighbours[i] & not_leaves) == 0){
                    return false;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(1 & (not_leaves >> i)){
                q.push(i);
                not_leaves ^= (1 << i);
                break;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int nei = not_leaves & neighbours[u];
            for(int i = 0; i < n; ++i){
                if(1 & (nei >> i)){
                    q.push(i);
                }
            }
            not_leaves ^= nei;
        }
        return (not_leaves == 0);
    };


    for(int mask = 0; mask < MAX_MASK; ++mask){
        if(check(mask)){
            ans = min(ans, n - 1 - __builtin_popcount(mask));
        }
    }

    cout << ans << '\n';
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
 
