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

class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};
vector<int> compress(int n, vector<int> &par){
    vector<int> deg(n), mp(n);
    for(int i = 1; i < n; ++i){
        ++deg[par[i]];
    }
    DSU dsu(n);
    for(int i = 1; i < n; ++i){
        int p = par[i];
        if(deg[p] == 1){
            dsu.merge(p, i);
        }
    }
    int cur_index = 0;
    vector<bool> vis(n);
    vector<int> index(n);
    for(int i = 0; i < n; ++i){
        int node = dsu.get_par(i);
        if(!vis[node]){
            vis[node] = true;
            index[node] = cur_index;
            ++cur_index;
        }
        mp[i] = index[node];
    }
    return mp;
}

void solve() {
    int n;
    cin >> n;

    vector<int> par(n);

    for(int i = 1; i < n; ++i){
        cin >> par[i];
        --par[i];
    }
    vector<int> mp = compress(n, par);
    int m = *max_element(mp.begin(), mp.end()) + 1;
    vector<int> deg(m);
    for(int i = 0; i < n; ++i){
        int node = mp[i];
        int p = mp[par[i]];
        if(p != node){
            par[node] = p;
        }
    }
    par.resize(m);
    for(int i = 1; i < m; ++i){
        ++deg[par[i]];
    }
    vector<int> leaves;
    for(int i = 0; i < m; ++i){
        if(deg[i] == 0){
            leaves.push_back(i);
        }
    }
    int l = leaves.size();

    map<string, vector<int>> nodes;

    for(int i = 0; i < n; ++i){
        int node = mp[i];
        int m;
        cin >> m;
        while(m--){
            string topic;
            cin >> topic;
            nodes[topic].push_back(node);
        }
    }
    auto check = [&](string topic){
        int freq = nodes[topic].size();
        if(freq < l){
            return false;
        }
        vector<bool> learn(n), vis(n);
        for(int node : nodes[topic]){
            learn[node] = true;
        }
        queue<int> q;
        for(int leaf : leaves){
            q.push(leaf);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(!learn[node]){
                if(vis[par[node]]){
                    return false;
                }
                q.push(par[node]);
                vis[par[node]] = true;
            }
        }
        return true;
    };
    int ans = 0;
    for(auto [t, v] : nodes){
        ans += check(t);
    }

    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}
