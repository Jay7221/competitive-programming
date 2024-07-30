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
 
bool check(vector<pair<int, int>> queries, vector<pair<int, int>> sols, vector<int> a){
    int m = queries.size();
    for(int ind = 0; ind < m; ++ind){
        int l, r, i, j;
        tie(l, r) = queries[ind];
        tie(i, j) = sols[ind];
        if((i < 0) || (j < 0)){
            continue;
        }
        if((i < l) || (j < l) || (r < i) || (r < j)){
            return false;
        }
        if(a[i] == a[j]){
            return false;
        }
    }
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> indices;
    for(int i = 1; i < n; ++i){
        if(a[i - 1] != a[i]){
            indices.push_back(i);
        }
    }


    auto get = [&](int l, int r){
        if(indices.empty() || (l == r) || (r < indices[0]) || (indices.back() < l + 1)){
            return make_pair(-1, -1);
        }
        int ind = *upper_bound(indices.begin(), indices.end(), l);
        if(ind > r){
            return make_pair(-1, -1);
        }
        return make_pair(ind, ind + 1);
    };

    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    vector<pair<int, int>> sols;
    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        int i, j;
        tie(i, j) = get(l, r);
        cout << i << ' ' << j << '\n';
        queries.push_back({l, r});
        sols.push_back({i - 1, j - 1});
    }
    cout << '\n';
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
 
