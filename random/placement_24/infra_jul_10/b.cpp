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
    private:
        int n;
        vector<int> par;
        vector<int> rank;
    public:
        DSU(int n){
            this -> n = n;
            rank = vector<int>(n, 1);
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
        }

        int get(int i){
            return (par[i] == i) ? i : par[i] = get(par[i]);
        }

        void merge(int u, int v){
            u = get(u);
            v = get(v);
            if(u != v){
                if(rank[u] < rank[v]){
                    swap(u, v);
                }
                par[v] = u;
                rank[u] += rank[v];
            }
        }

        int getSize(int u){
            u = get(u);
            return rank[u];
        }
};
 
vector<int> getTheGroups(int n, vector<string> queryType, vector<int> student1, vector<int> student2){
    vector<int> res;
    int q = queryType.size();
    DSU dsu(n + 2);
    for(int i = 0; i < q; ++i){
        int u = student1[i];
        int v = student2[i];
        if(queryType[i] == "Friend"){
            dsu.merge(u, v);
        }
        else{
            if(dsu.get(u) != dsu.get(v)){
                res.push_back(dsu.getSize(u) + dsu.getSize(v));
            }
            else{
                res.push_back(dsu.getSize(u));
            }
        }
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<string> query(q);
    vector<int> student1(q), student2(q);
    for(int i = 0; i < q; ++i){
        cin >> query[i] >> student1[i] >> student2[i];
    }

    for(int res: getTheGroups(n, query, student1, student2)){
        cout << res << '\n';
    }
    
    return 0;
}
 
