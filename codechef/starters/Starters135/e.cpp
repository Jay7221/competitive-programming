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
 
const int MAX = 5e3 + 7;
 
void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> backlink(MAX, -1);
    vector<bool> vis(MAX);
    vis[w] = true;

    function<void(int)> dfs = [&](int u){
        for(int i = n - 1; i >= 0; --i){
            if(a[i] <= u){
                break;
            }
            int v = a[i] - u;
            if(!vis[v]){
                vis[v] = true;
                backlink[v] = i;
                dfs(v);
            }
        }
    };

    dfs(w);
    int d = -1;
    for(int i = 0; i < a[0]; ++i){
        if(vis[i]){
            d = i;
            break;
        }
    }
    if(d == -1){
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    while(backlink[d] != -1){
        ans.push_back(backlink[d]);
        d = a[backlink[d]] - d;
    }
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < n; ++i){
        ans.push_back(i);
        ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int elem: ans){
        cout << elem + 1 << ' ';
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
 
