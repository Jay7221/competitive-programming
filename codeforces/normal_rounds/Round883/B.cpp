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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void solve() {
    char board[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    auto checkRow = [&](int r){
        for(int i = 1; i < 3; ++i){
            if(board[r][i] != board[r][0]){
                return false;
            }
        }
        return true;
    };
    auto checkCol = [&](int c){
        for(int i = 1; i < 3; ++i){
            if(board[i][c] != board[0][c]){
                return false;
            }
        }
        return true;
    };
    auto checkDiag1 = [&](){
        return ((board[1][1] != '.') && ((board[1][1] == board[0][0]) && (board[1][1] == board[2][2])));
    };
    auto checkDiag2 = [&](){
        return ((board[1][1] != '.') && ((board[1][1] == board[0][2]) && (board[1][1] == board[2][0])));
    };
    string winner = "DRAW";
    for(int i = 0; i < 3; ++i){
        if(checkRow(i) && board[i][0] != '.'){
            winner.clear();
            winner.push_back(board[i][0]);
        }
        if(checkCol(i) && board[0][i] != '.'){
            winner.clear();
            winner.push_back(board[0][i]);
        }
    }
    if(checkDiag1() || checkDiag2()){
        winner.clear();
        winner.push_back(board[1][1]);
    }
    cout << winner << '\n';
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
 
