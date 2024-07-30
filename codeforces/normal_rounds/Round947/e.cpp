#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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
    int n, q;
    cin >> n >> q;

    vector<int> c(n), tmp(n);
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; ++i){
        cin >> tmp[i];
    }

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n, -1);
    // children[i] = number of black children of i
    vector<int> children(n);

    function<void(int, int)> dfs = [&](int u, int p){
        par[u] = p;
        for(int v: adj[u]){
            if(v != p){
                dfs(v, u);
            }
        }
    };

    dfs(0, -1);

    // Number of black nodes with white parent
    int cnt0 = 0;
    // Number of nodes with two black children
    int cnt2 = 0;
    // Number of nodes with more than two black children
    int cnt3 = 0;


    auto is_parent_white = [&](int u){
        return (par[u] == -1) || (c[par[u]] == 0);
    };

    set<int> two_nodes;
    auto update = [&](int u){
        c[u] = 1 - c[u];
        int p = par[u];
        if(c[u] == 0){
            cnt0 += children[u];
            if(is_parent_white(u)){
                --cnt0;
            }
            if(p != -1){
                --children[p];
                if(children[p] == 1){
                    two_nodes.erase(p);
                    --cnt2;
                }
                else if(children[p] == 2){
                    two_nodes.insert(p);
                    ++cnt2;
                    --cnt3;
                }
            }
        }
        else{
            cnt0 -= children[u];
            if(is_parent_white(u)){
                ++cnt0;
            }
            if(p != -1){
                ++children[p];
                if(children[p] == 2){
                    two_nodes.insert(p);
                    ++cnt2;
                }
                else if(children[p] == 3){
                    two_nodes.erase(p);
                    --cnt2;
                    ++cnt3;
                }
            }
        }
    };

    auto check = [&](){
        if(cnt0 != 1){
            return false;
        }
        if(cnt3 != 0){
            return false;
        }
        if(cnt2 > 1){
            return false;
        }
        if(cnt2 == 1){
            int u = *two_nodes.begin();
            if(!is_parent_white(u)){
                return false;
            }
        }
        return true;
    };

    for(int u = 0; u < n; ++u){
        if(tmp[u] == 1){
            update(u);
        }
    }

    while(q--){
        int u;
        cin >> u;
        --u;
        update(u);
        if(check()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
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
 
