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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = (s[i] - '0');
    }
    auto calc = [&](){
        vector<int> c(2);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == 0){
                ++c[0];
                ans += c[1];
            }
            else{
                ++c[1];
                ans -= c[0];
            }
        }
        return ans;
    };
    int noMoves = 0;
    int cur = abs(calc());
    while(cur > 0){
        ++noMoves;
        int mn = cur;
        int l, r;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                swap(arr[i], arr[j]);
                int tmp = abs(calc());
                if(tmp < mn){
                    mn = tmp;
                    l = i, r = j;
                }
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[l], arr[r]);
        cur = mn;
    }
    cout << noMoves << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
