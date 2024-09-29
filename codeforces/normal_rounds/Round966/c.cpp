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
 
vector<int> compressIndex(vector<int> &a){
    map<int, int> mp;
    int cur = 0;
    for(int &elem: a){
        if(mp.find(elem) == mp.end()){
            mp[elem] = cur;
            ++cur;
        }
        elem = mp[elem];
    }
    return a;
}

bool check(vector<int> &a, string &s){
    if(a.size() != s.size()){
        return false;
    }
    map<char, int> mp;
    map<int, bool> vis;
    for(int i = 0; i < (int)s.size(); ++i){
        char ch = s[i];
        if(mp.find(ch) == mp.end()){
            if(vis[a[i]]){
                return false;
            }
            mp[ch] = a[i];
            vis[a[i]] = true;
        }
        if(mp[ch] != a[i]){
            return false;
        }
    }
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    a = compressIndex(a);

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;
        if(check(a, s)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
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
 
