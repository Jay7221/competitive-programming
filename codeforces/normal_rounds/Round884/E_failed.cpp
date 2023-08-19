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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
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
void solve() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<int>> rot(n - 1, vector<int>(m - 1));
    // l -> 1, r -> 2
    bool flag = true;
    for(int i = 0; i < k; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        if(y1 < y2){
            if(rot[x1][y1] == 2){
                flag = false;
            }
            rot[x1][y1] = 1;
        }else{
            if(rot[x1][y2] == 1){
                flag = false;
            }
            rot[x1][y2] = 2;
        }
    }
    DSU dsu(m - 1);
    for(int i = 0; i < n - 1; ++i){
        int one = -1, two = -1;
        for(int j = 0; j < m - 1; ++j){
            if(rot[i][j] == 1){
                if(one == -1){
                    one = j;
                }else{
                    dsu.merge(j, one);
                }
            }
            if(rot[i][j] == 2){
                if(two == -1){
                    two = j;
                }else{
                    dsu.merge(j, two);
                }
            }
        }
    }
    map<int, vector<int>> group;
    for(int j = 0; j < m - 1; ++j){
        group[dsu.get_par(j)].push_back(j);
    }
    for(int i = 0; (i < n - 1) && flag; ++i){
        for(auto [f, v] : group){
            int type = -1;
            for(int j : v){
                if(rot[i][j] == 0){
                    continue;
                }
                if(type == -1){
                    type = rot[i][j];
                }else{
                    if(type != rot[i][j]){
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
 
