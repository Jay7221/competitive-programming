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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        --p[i];
    }

    if(k == 1){
        for(int i = 0; i < n; ++i){
            if(p[i] != i){
                return false;
            }
        }
        return true;
    }

    vector<bool> vis(n);
    vector<int> tour;
    function<void(int)> dfs;

    dfs = [&](int u){
        if(!vis[u]){
            vis[u] = true;
            if(!vis[p[u]]){
                dfs(p[u]);
            }
            tour.push_back(u);
        }
    };

    for(int i = 0; i < n; ++i){
        dfs(i);
    }
    reverse(tour.begin(), tour.end());

    map<int, int> ind;
    for(int i = 0; i < n; ++i){
        ind[tour[i]] = i;
    }

    vis.assign(n, false);

    for(int i = 0; i < n; ++i){
        if(ind[p[i]] <= ind[i]){
            int cur = i;
            int len = 0;
            while(!vis[cur]){
                ++len;
                vis[cur] = true;
                cur = p[cur];
            }
            if(len != k){
                return false;
            }
        }
    }

    return true;
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
 
