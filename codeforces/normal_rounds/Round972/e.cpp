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
    int l, n, m;
    cin >> l >> n >> m;

    vector<int> a(l);
    for(int i = 0; i < l; ++i){
        cin >> a[i];
    }

    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> b[i][j];
        }
    }

    map<int, vector<pair<int, int>>> ind;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ind[b[i][j]].push_back({i, j});
        }
    }

    map<int, bool> vis;
    int len = l;
    for(int i = 0; i < l; ++i){
        if(vis[a[i]]){
            len = i;
            break;
        }
        vis[a[i]] = true;
    }
    

    // maxY[x] => the max y, wuch that for some xk >= x, (xk, y) is a winning square
    vector<int> maxY(n + 1, -1);

    for(int i = len - 1; i >= 0; --i){
        vector<pair<int, int>> winPoints;
        for(auto [x, y]: ind[a[i]]){
            if(maxY[x + 1] <= y){
                winPoints.push_back({x, y});
            }
        }
        maxY.assign(n + 1, -1);
        for(auto [x, y]: winPoints){
            maxY[x] = max(maxY[x], y);
        }
        for(int i = n - 1; i >= 0; --i){
            maxY[i] = max(maxY[i], maxY[i + 1]);
        }
    }

    return (maxY[0] != -1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "T\n";
        }
        else{
            cout << "N\n";
        }
    }
    
    return 0;
}
 
