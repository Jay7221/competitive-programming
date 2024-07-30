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
 
int get_mex(vector<int> arr){
    sort(arr.begin(), arr.end());
    int cur_mex = 0;
    for(int elem: arr){
        if(elem == cur_mex){
            ++cur_mex;
        }
    }
    return cur_mex;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int mex = get_mex(arr);
    if(mex == 0){
        cout << 2 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 2 << ' ' << n << '\n';
        return;
    }

    vector<bool> vis(mex);
    vector<pair<int, int>> segments;


    int l = 0;
    int cur_mex = 0;
    for(int r = 0; r < n; ++r){
        if(arr[r] >= mex){
            continue;
        }
        vis[arr[r]] = true;
        while((cur_mex < mex) && vis[cur_mex]){
            ++cur_mex;
        }
        if(cur_mex == mex){
            segments.push_back({l, r});
            l = r + 1;
            vis.assign(mex, false);
            cur_mex = 0;
        }
    }
    if(l < n){
        segments.back().second = n - 1;
    }

    int k = segments.size();
    if(k == 1){
        cout << -1 << '\n';
    }
    else{
        cout << k << '\n';
        for(auto [l, r]: segments){
            cout << l + 1 << ' ' << r + 1 << '\n';
        }
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
 
