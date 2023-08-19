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
        int size(int u){
            u = get_par(u);
            return rank[u];
        }
        int size(){
            return n;
        }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    vector<vector<int>> adj(n);
    // Color of edges :
    // R -> 0
    // B -> 1
    for(int i = 0; i < m; ++i){
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(i);
        adj[b].push_back(i);
        edges[i] = {a, b, (c == 'B')};
    }
    string colors;
    cin >> colors;
    vector<int> color(n);
    for(int i = 0; i < n; ++i){
        color[i] = (colors[i] == 'B');
    }
    DSU dsu(n);
    vector<bool> done(n);

    vector<int> ans;

    // Short edges that connect same color edges and have the same color
    for(int i = 0; i < m; ++i){
        int a = edges[i][0];
        int b = edges[i][1];
        int c = edges[i][2];
        if((color[a] == c) && (color[b] == c)){
            if(dsu.get_par(a) != dsu.get_par(b)){
                ans.push_back(i);
                dsu.merge(a, b);
                done[a] = done[b] = true;
            }
        }
    }
    auto grow = [&](int u){
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int id : adj[u]){
                int a = edges[id][0];
                int b = edges[id][1];
                int c = edges[id][2];

                int v = (a == u) ? b : a;

                if(dsu.get_par(u) == dsu.get_par(v)){
                    continue;
                }
                if(done[v]){
                    continue;
                }

                if(c == color[v]){
                    ans.push_back(id);
                    done[v] = true;
                    q.push(v);
                    dsu.merge(u, v);
                }
            }
        }
    };
    // grow edges in the forest 
    // add edges which are of different color than the node in the forest
    for(int i = 0; i < n; ++i){
        if(done[i]){
            grow(i);
        }
    }
    // add all the remaining edges to make the forest a tree
    for(int i = 0; i < m; ++i){
        int a = edges[i][0];
        int b = edges[i][1];
        if(dsu.get_par(a) != dsu.get_par(b)){
            ans.push_back(i);
            dsu.merge(a, b);
        }
    }


    bool flag = ((int)ans.size() == n - 1);
    sort(ans.begin(), ans.end());
    for(bool elem : done){
        flag &= elem;
    }
    if(flag){
        cout << "Yes\n";
        for(int elem : ans){
            ++elem;
            cout << elem << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "No\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
