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
    int n, m, k;
    cin >> n >> m >> k;
    if((k < n + m - 2) || ((k % 2) != ((n + m) % 2))){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    bool flag = false;
    if(((n + m - 2) % 4) != (k % 4)){
        flag = true;
    }
    cerr << flag << '\n';
    // Rows
    vector<vector<bool>> rows(n, vector<bool>(m - 1));
    vector<vector<bool>> columns(n - 1, vector<bool>(m));

    if(flag){
        columns[1][0] = columns[0][0];
    }
    else{
        columns[1][0] = (columns[0][0] ^ 1);
    }
    for(int i = 2; i < n - 1; ++i){
        columns[i][0] = (columns[i - 1][0] ^ 1);
    }
    rows[n - 1][0] = columns[n - 2][0];
    for(int j = 1; j < m - 1; ++j){
        rows[n - 1][j] = (rows[n - 1][j - 1] ^ 1);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m - 1; ++j){
            if(rows[i][j]){
                cout << "R ";
            }
            else{
                cout << "B ";
            }
        }
        cout << '\n';
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            if(columns[i][j]){
                cout << "B ";
            }
            else{
                cout << "R ";
            }
        }
        cout << '\n';
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
 
