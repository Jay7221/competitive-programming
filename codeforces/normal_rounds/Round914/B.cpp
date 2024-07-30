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
 

vector<int> get_breaks(vector<ll> a){
    vector<int> ans;
    sort(a.begin(), a.end());
    ll sum = 0;
    int n = a.size();
    for(int i = 0; i < n; ++i){
        if(sum < a[i]){
            ans.push_back(i);
        }
        sum += a[i];
    }
    ans.push_back(n);
    return ans;
}
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> arr = get_breaks(a);
    map<ll, int> ind;
    vector<ll> b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i){
        ind[b[i]] = i;
    }

    vector<int> ans(n);
    for(int i = 0; i < n; ++i){
        ans[i] = *upper_bound(arr.begin(), arr.end(), ind[a[i]]);
        --ans[i];
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
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
 
