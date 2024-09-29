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
    vector<string> arr(2);
    for(int i = 0; i < 2; ++i){
        cin >> arr[i];
    }

    vector<tuple<int, int, char>> d1 = {
        {0, 0, 'x'},
        {0, 1, '.'},
        {0, 2, 'x'},
        {1, 0, '.'},
        {1, 1, '.'},
        {1, 2, '.'},
    };

    vector<tuple<int, int, char>> d2 = {
        {0, 0, '.'},
        {0, 1, '.'},
        {0, 2, '.'},
        {1, 0, 'x'},
        {1, 1, '.'},
        {1, 2, 'x'},
    };

    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < 2) && (y < n));
    };

    auto check1 = [&](int x, int y){
        for(auto [dx, dy, ch]: d1){
            if(!check(x + dx, y + dy) || (arr[x + dx][y + dy] != ch)){
                return false;
            }
        }
        return true;
    };
    auto check2 = [&](int x, int y){
        for(auto [dx, dy, ch]: d2){
            if(!check(x + dx, y + dy) || (arr[x + dx][y + dy] != ch)){
                return false;
            }
        }
        return true;
    };

    int res = 0;
    for(int j = 0; j < n; ++j){
        if(check1(0, j) || check2(0, j)){
            ++res;
        }
    }

    cout << res << '\n';
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
 
