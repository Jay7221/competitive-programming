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
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s;
    cin >> s;

    vector<bool> isLeaf(n);
    for(int i = 1; i < n; ++i){
        isLeaf[i] = (adj[i].size() == 1);
    }

    int res = 0;
    if(s[0] == '?'){
        int cnt0 = 0, cnt1 = 0, freeLeaves = 0, internalNodes = 0;
        for(int i = 1; i < n; ++i){
            if(isLeaf[i]){
                cnt0 += (s[i] == '0');
                cnt1 += (s[i] == '1');
                freeLeaves += (s[i] == '?');
            }
            else{
                internalNodes += (s[i] == '?');
            }
        }
        res = max(cnt0, cnt1) + freeLeaves / 2;
        if(internalNodes & 1){
            ++freeLeaves;
            res = max(res, min(cnt0, cnt1) + freeLeaves / 2);
        }
    }
    else{
        int freeLeaves = 0;
        for(int i = 1; i < n; ++i){
            if(isLeaf[i]){
                if(s[i] == '?'){
                    ++freeLeaves;
                }
                else if(s[i] != s[0]){
                    ++res;
                }
            }
        }
        res += (freeLeaves + 1) / 2;
    }

    cout << res << '\n';
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
 
