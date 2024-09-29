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
 
const int MAX_N = 300;
int minValue[MAX_N][MAX_N][MAX_N];
int maxValue[MAX_N][MAX_N][MAX_N];

int beauty(int row_start, int row_end, int col_start, int col_end){
    if(row_start > row_end){
        return 0;
    }
    if(col_start > col_end){
        return 0;
    }
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for(int row = row_start; row <= row_end; ++row){
        maxVal = max(maxVal, maxValue[row][col_start][col_end]);
        minVal = min(minVal, minValue[row][col_start][col_end]);
    }
    int res = maxVal - minVal;
    return res;
}
int get_ans(int n, vector<vector<int>> &grid){
    // minValue[i][l][r] = min value row[i][l:r]
    // maxValue[i][l][r] = max value row[i][l:r]
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                minValue[i][j][k] = INT_MAX;
                maxValue[i][j][k] = INT_MIN;
            }
        }
    }
    for(int row = 0; row < n; ++row){
        for(int col = 0; col < n; ++col){
            minValue[row][col][col] = grid[row][col];
            maxValue[row][col][col] = grid[row][col];
        }
        for(int len = 2; len <= n; ++len){
            for(int l = 0, r = len - 1; r < n; ++l, ++r){
                minValue[row][l][r] = min({minValue[row][l][r], minValue[row][l][r - 1], minValue[row][l + 1][r]});
                maxValue[row][l][r] = max({maxValue[row][l][r], maxValue[row][l][r - 1], maxValue[row][l + 1][r]});
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        vector<int> v;
        v.push_back(beauty(0, i, 0, i));
        v.push_back(beauty(i + 1, n - 1, i + 1, n - 1));
        int len = min(i + 1, n - 1 - i);
        for(int row = len - 1; row <= i; ++row){
            for(int col = i + 1 + len - 1; col < n; ++col){
                v.push_back(beauty(row - len + 1, row, col - len + 1, col));
                v.push_back(beauty(col - len + 1, col, row - len + 1, row));
            }
        }
        sort(v.rbegin(), v.rend());
        res = max(res, v[0] + v[1]);
    }


    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }

    cout << get_ans(n, grid);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
