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
        bool cmp(int u, int v){
            u = get_par(u);
            v = get_par(v);
            return (u == v);
        }
        int size(){
            return n;
        }
};
 
void solve() {
    int m, n;
    cin >> m >> n;
    int s;
    cin >> s;
    int mx_num = 0, mx_area = 0;

    int k;
    cin >> k;
    vector<vector<bool>> up(m + 1, vector<bool>(n + 1));
    vector<vector<bool>> down(m + 1, vector<bool>(n + 1));
    vector<vector<bool>> left(m + 1, vector<bool>(n + 1));
    vector<vector<bool>> right(m + 1, vector<bool>(n + 1));
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2){
            swap(x1, x2);
        }
        if(y1 > y2){
            swap(y1, y2);
        }
        for(int i = x1; i < x2; ++i){
            down[i][y1] = true;
            if(y1 > 0){
                up[i][y1 - 1] = true;
            }

        }
        for(int j = y1; j < y2; ++j){
            left[x1][j] = true;
            if(x1 > 0){
                right[x1 - 1][j] = true;
            }
        }
    }

    auto get = [&](int lx, int rx, int ly, int ry){
        int num = 0, area = 0;
        map<pair<int, int>, int> mp;
        int ind = 0;
        for(int i = lx; i <= rx; ++i){
            for(int j = ly; j <= ry; ++j){
                mp[{i, j}] = ind;
                ++ind;
            }
        }
        DSU dsu(ind + 1);
        for(int i = lx; i <= rx; ++i){
            if(!down[i][ly]){
                dsu.merge(mp[{i, ly}], ind);
            }
            if(!up[i][ry]){
                dsu.merge(mp[{i, ry}], ind);
            }
        }
        for(int j = ly; j <= ry; ++j){
            if(!left[lx][j]){
                dsu.merge(mp[{lx, j}], ind);
            }
            if(!right[rx][j]){
                dsu.merge(mp[{rx, j}], ind);
            }
        }

        for(int i = lx; i <= rx; ++i){
            for(int j = ly; j <= ry; ++j){
                if(!left[i][j] && (i > lx)){
                    dsu.merge(mp[{i, j}], mp[{i - 1, j}]);
                }
                if(!right[i][j] && (i < rx)){
                    dsu.merge(mp[{i, j}], mp[{i + 1, j}]);
                }
                if(!up[i][j] && (j < ry)){
                    dsu.merge(mp[{i, j}], mp[{i, j + 1}]);
                }
                if(!down[i][j] && (j > ly)){
                    dsu.merge(mp[{i, j}], mp[{i, j - 1}]);
                }
            }
        }

        num = dsu.size() - 1;
        for(int i = lx; i <= rx; ++i){
            for(int j = ly; j <= ry; ++j){
                if(!dsu.cmp(mp[{i, j}], ind)){
                    ++area;
                }
            }
        }
        cerr << lx << ' ' << rx << ", " << ly << ' ' << ry << " : " << num << ' ' << area << '\n';
        return make_pair(num, area);
    };

    for(int lx = 0, rx = s - 1; rx < m; ++lx, ++rx){
        for(int ly = 0, ry = s - 1; ry < n; ++ly, ++ry){
            int num, area;
            tie(num, area) = get(lx, rx, ly, ry);
            if(num > mx_num){
                mx_num = num;
                mx_area = area;
            }
            else if(num == mx_num){
                mx_area = max(mx_area, area);
            }
        }
    }

    for(int i = 0; i < m; ++i){
        cerr << up[i] << '\n';
    }


    cout << mx_num << ' ' << mx_area;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
