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
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n - 1; ++i){
        if(((s[i] == '0') && (s[i + 1] == '1')) || ((s[i] == '1') && (s[i + 1] == '0'))){
            return false;
        }
    }
    stack<int> st;
    int len = 0, mn = 0, mx = 0;
    for(char ch : s){
        if(ch == '+'){
            ++len;
        }
        else if(ch == '-'){
            --len;
            if(mn > len){
                mn = 0;
            }
            if(mx > len){
                --mx;
            }
        }
        else if(ch == '0'){
            if(len < 2){
                return false;
            }
            if(mx == len){
                return false;
            }
            if(mn == 0){
                mn = len;
            }
        }
        else{
            if(mn != 0){
                return false;
            }
            mx = len;
        }
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
