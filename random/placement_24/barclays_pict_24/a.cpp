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
 
string getS(string a, string b){
    int n = a.size();
    int m = b.size();
    string s;
    for(int i = 0; i < m; ++i){
        if(b[i] == 'T'){
            for(int j = 0; j < n; ++j){
                if(i + j < s.size()){
                    if(s[i + j] != a[j]){
                        return "-1";
                    }
                }
                else{
                    s.push_back(a[j]);
                }
            }
        }
        else{
            bool match = true;
            for(int j = 0; j < n; ++j){
                if(i + j < s.size()){
                    if(s[i + j] != a[j]){
                        match = false;
                        break;
                    }
                }
                else{
                    if(a[j] == 'A'){
                        s.push_back('B');
                    }
                    else{
                        s.push_back('A');
                    }
                    match = false;
                    break;
                }
            }
            if(match){
                return "-1";
            }
        }
    }
    while(s.size() < n + m - 1){
        s.push_back('A');
    }
    return s;
}
 
void solve() {
    string a, b;
    cin >> a >> b;
    cout << getS(a, b) << '\n';
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
 
