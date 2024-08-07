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
 
vector<bool> get_arr(string &s, char ch){
    int n = s.size();
    vector<bool> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = (s[i] == ch);
    }
    return arr;
}
int get_cost(string &s, char ch){
    int n = s.size();
    vector<bool> arr = get_arr(s, ch);
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum == 0){
        return n;
    }
    int ans = sum;
    int cur = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i]){
            ++cur;
        }
        if((i >= sum) && (arr[i - sum])){
            --cur;
        }
        ans = min(ans, sum - cur);
    }
    return ans;
}
 
void solve() {
    string s;
    cin >> s;
    int ans = s.size();
    for(char ch  = 'a'; ch <= 'z'; ++ch){
        ans = min(ans, get_cost(s, ch));
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
 
