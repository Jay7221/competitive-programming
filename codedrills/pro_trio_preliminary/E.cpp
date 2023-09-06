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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> index(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        index[a[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i){
        index[i].push_back(n);
        reverse(index[i].begin(), index[i].end());
    }
    // m => {index, char}
    multiset<pair<int, int>> m;
    // vis[i] => is i on the keyset
    vector<bool> vis(n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int key = a[i];

        if(vis[key]){
            m.erase(m.find({index[key].back(), key}));
        }

        index[key].pop_back();

        if(!vis[key]){
            ++ans;

            if((int)m.size() == k){
                int _, kk;
                tie(_, kk) = *(--m.end());
                vis[kk] = false;
                m.erase(--m.end());
            }

            vis[key] = true;
        }
        m.insert({index[key].back(), key});
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 

