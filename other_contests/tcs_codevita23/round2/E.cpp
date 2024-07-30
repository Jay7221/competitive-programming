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
 
template<typename T>
vector<T> operator-(vector<T> v1, vector<T> v2){
    vector<T> ans = v1;
    for(int i = 0; i < (int)v1.size(); ++i){
        ans[i] = v1[i] - v2[i];
    }
    return ans;
}
template<typename T>
vector<T> operator+(vector<T> v1, vector<T> v2){
    vector<T> ans = v1;
    for(int i = 0; i < (int)v1.size(); ++i){
        ans[i] = v1[i] + v2[i];
    }
    return ans;
}
 
void solve() {
    int h;
    cin >> h;
    vector<int> height(5);
    for(int i = 0; i < 5; ++i){
        cin >> height[i];
    }

    sort(height.rbegin(), height.rend());


    vector<vector<vector<int>>> dp(h + 1, {{0}, {0, 0, 0, 0, 0}});
    vector<bool> vis(h + 1);
    vis[0] = true;

    for(int i = 0; i < 5; ++i){
        vector<vector<int>> cur = {{1}, {0, 0, 0, 0, 0}};
        cur[1][i] = 1;

        for(int val = height[i]; val <= h; ++val){
            if(vis[val - height[i]]){
                vis[val] = true;
                dp[val] = max(dp[val], dp[val - height[i]] + cur);
            }
        }
    }


    if(vis[h]){
        vector<vector<int>> v;
        for(int i = 0; i < 5; ++i){
            v.push_back({-dp[h][1][i], height[i]});
        }
        sort(v.begin(), v.end());
        bool prev = false;
        for(int i = 0; i < 5; ++i){
            if(v[i][0] != 0){
                if(prev){
                    cout << ' ';
                }
                else{
                    prev = true;
                }
                cout << v[i][1];
            }
        }
    }
    else{
        cout << "Impossible";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
