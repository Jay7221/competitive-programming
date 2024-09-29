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
 
vector<pair<int, int>> edges;
vector<vector<bool>> vis;

int query(int a, int b){
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int x;
    cin >> x;
    --x;
    return x;
}

void answer(){
    cout << "! ";
    for(auto [u, v]: edges){
        cout << u + 1 << " " << v + 1 << " ";
    }
    cout << endl;
}

void find(int a, int b){
    if(a > b){
        swap(a, b);
    }

    if(vis[a][b]){
        return;
    }
    vis[a][b] = true;

    int x = query(a, b);
    if(x == a){
        edges.push_back({a, b});
    }
    else{
        find(a, x);
        find(b, x);
    }
}
 
void solve() {
    int n;
    cin >> n;

    edges.clear();
    vis = vector<vector<bool>>(n, vector<bool>(n));

    for(int i = 1; i < n; ++i){
        find(0, i);
    }

    answer();
}
 
int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
