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
    string s;
    cin >> s;
    vector<int> v0, v1;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            v0.push_back(i);
        }
        else{
            v1.push_back(i);
        }
    }
    int ans = min(v0.size(), v1.size());
    if(v0.size() < v1.size()){
        int num01 = 0;
        while(v0.size() < v1.size()){
            int ind = v1.back();
            v1.pop_back();
            ++num01;
            while(!v0.empty() && (v0.back() > ind)){
                v0.pop_back();
            }
            ans = max(ans, (int)min(v0.size() + num01, v1.size()));
        }
    }
    else{
        reverse(v0.begin(), v0.end());
        reverse(v1.begin(), v1.end());
        int num01 = 0;
        while(v0.size() > v1.size()){
            int ind = v0.back();
            v0.pop_back();
            ++num01;
            while(!v1.empty() && (v1.back() < ind)){
                v1.pop_back();
            }
            ans = max(ans, (int)min(v0.size(), v1.size() + num01));
        }
    }
    cout << ans << '\n';
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
 
