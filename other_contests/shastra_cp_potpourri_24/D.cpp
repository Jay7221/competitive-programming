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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    int ex, ey;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            if(mat[i][j] == 'E'){
                ex = i, ey = j;
            }
        }
    }
    int pre[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            pre[i][j] = (mat[i][j] == 'o');
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < m; ++j){
            pre[i][j] += pre[i][j - 1];
        }
        if(i > 0){
            for(int j = 0; j < m; ++j){
                pre[i][j] += pre[i - 1][j];
            }
        }
    }
    int r1i = ex;
    int r2i = n - 1 - ex;
    int r1j =  ey;
    int r2j = m - 1 - ey;
    int ans = 0;
    for(int lefti = 0; lefti <= r1i; ++lefti){
        for(int righti = 0; righti <= r2i; ++righti){
            if(lefti + righti > max(r1i, r2i)){
                continue;
            }
            for(int leftj = 0; leftj <= r1j; ++leftj){
                for(int rightj = 0; rightj <= r2j; ++rightj){

                    if(leftj + rightj > max(r1j, r2j)){
                        continue;
                    }

                    int x1 = ex - lefti, x2 = ex + righti;
                    int y1 = ex - leftj, y2 = ex + rightj;
                    int cur = pre[x2][y2];
                    if(x1 > 0){
                        cur -= pre[x1 - 1][y2];
                    }
                    if(y1 > 0){
                        cur -= pre[x2][y1 - 1];
                    }
                    if((x1 > 0) && (y1 > 0)){
                        cur += pre[x1 - 1][y1 - 1];
                    }
                    if(cur > ans){
                        ans = cur;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
