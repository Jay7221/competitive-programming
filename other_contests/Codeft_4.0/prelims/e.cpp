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
 
 
void solve() {
    int n;
    cin >> n;
    vector<map<int, int>> freq_of_merit(n), num_of_merits_with_freq(n);
    vector<int> ans(n);
    vector<int> merit(n);
    for(int i = 0; i < n; ++i){
        cin >> merit[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto merge = [&](int i, int j){
        if(freq_of_merit[i].size() < freq_of_merit[j].size()){
            swap(freq_of_merit[i], freq_of_merit[j]);
            swap(num_of_merits_with_freq[i], num_of_merits_with_freq[j]);
        }
        for(auto [mer, fr]: freq_of_merit[j]){
            if(freq_of_merit[i][mer] > 0){
                --num_of_merits_with_freq[i][freq_of_merit[i][mer]];
            }
            freq_of_merit[i][mer] += fr;
            ++num_of_merits_with_freq[i][freq_of_merit[i][mer]];
        }
    };

    function<void(int, int)> dfs = [&](int u, int p){
        ++freq_of_merit[u][merit[u]];
        ++num_of_merits_with_freq[u][1];
        for(int v: adj[u]){
            if(v != p){
                dfs(v, u);
                merge(u, v);
            }
        }
        ans[u] = num_of_merits_with_freq[u][merit[u]];
    };

    dfs(0, -1);

    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
