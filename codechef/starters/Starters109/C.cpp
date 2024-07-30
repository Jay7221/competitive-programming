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
    int n;
    cin >> n;
    vector<int> a(n), colorA(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> colorA[i];
    }
    vector<int> b(n), colorB(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> colorB[i];
    }

    vector<multiset<int>> color(2 * n + 1);
    vector<bool> vis(2 * n + 1);
    for(int i = 0; i < n; ++i){
        color[colorA[i]].insert(a[i]);
        color[colorB[i]].insert(b[i]);
        vis[colorB[i]] = true;
    }

    int cur = -1;
    for(int i = 0; i < n; ++i){
        int c = colorA[i];
        if(!vis[c]){
            if(a[i] < cur){
                return false;
            }
            cur = max(cur, a[i]);
        }
        if(color[c].lower_bound(cur) == color[c].end()){
            return false;
        }
        cur = *(color[c].lower_bound(cur));
        color[c].erase(color[c].lower_bound(cur));
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}
 
