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
 
int solve() {
    int p;
    cin >> p;
    int o;
    cin >> o;
    vector<pair<int, int>> v;
    for(int i = 0; i < o; ++i){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    ll res = 0;
    DSU dsu(o);
    sort(v.begin(), v.end());
    int cur = v[0].second;
    for(int i = 1; i < o; ++i){
        if(v[i].first <= cur){
            dsu.merge(i - 1, i);
        }
        else{
            res += v[i].first - cur - 1;
        }
        cur = max(cur, v[i].second);
    }
    res += p - v.back().second;
    vector<int> maxL(o), minR(o);
    for(int i = 0; i < o; ++i){
        int id = dsu.get_par(i);
        tie(maxL[id], minR[id]) = v[i];
    }
    for(int i = 0; i < o; ++i){
        int id = dsu.get_par(i);
        int l, r;
        tie(l, r) = v[i];
        maxL[id] = max(maxL[id], l);
        minR[id] = min(minR[id], r);
        if(maxL[id] > minR[id]){
            return -1;
        }
    }
    return dsu.size() + res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cout << solve() << '\n';
    
    return 0;
}
 
