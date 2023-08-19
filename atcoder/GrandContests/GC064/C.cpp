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
    vector<ll> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
    }
    function<int(vector<pair<ll, ll>>)> gurdy;
    auto allSame = [](vector<pair<ll, ll>> &v){
        int parity = -1;
        for(auto [l, r] : v){
            if(l < r){
                return false;
            }
            if(parity == -1){
                parity = l % 2;
            }
            if(parity != (l % 2)){
                return false;
            }
        }
        return true;
    };
    map<vector<pair<ll, ll>>, int> mp;
    map<vector<pair<ll, ll>>, bool> vis;
    auto mex = [](vector<int> v){
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); ++i){
            if(i != v[i]){
                return i;
            }
        }
        return (int)(v.size());
    };
    gurdy = [&mp, &vis, &gurdy, &allSame, &mex](vector<pair<ll, ll>> v){
        if(vis[v]){
            return mp[v];
        }
        if(v.empty()){
            return 0;
        }
        if(allSame(v)){
            return 1;
        }
        vector<pair<ll, ll>> even, odd;
        for(auto [l, r] : v){
            int evenL = l;
            int evenR = r;
            int oddL = l;
            int oddR = r;
            if(l & 1){
                ++evenL;
            }
            else{
                ++oddL;
            }
            if(r & 1){
                --evenR;
            }
            else{
                --oddR;
            }
            evenL >>= 1;
            evenR >>= 1;
            oddL >>= 1;
            oddR >>= 1;
            if(evenL <= evenR){
                even.push_back({evenL, evenR});
            }
            if(oddL <= oddR){
                odd.push_back({oddL, oddR});
            }
        }
        vis[v] = true;
        return mp[v] = mex((vector<int>){gurdy(even), gurdy(odd)});
    };
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({l[i], r[i]});
    }
    int flag = gurdy(v);
    if(flag){
        cout << "Takahashi\n";
    }
    else{
        cout << "Aoki\n";
    }
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
 
