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
 
const int INF = 1e9 + 7;

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

vector<int> get(int area, vector<int> &roomSize){
    vector<vector<vector<int>>> dp(area + 1,
                                   {{0}, {0, 0, 0, 0}});
    vector<bool> vis(area);
    vis[0] = true;
    for(int i = 0; i < 4; ++i){
        vector<vector<int>> cur = {{1}, {0, 0, 0, 0}};
        cur[1][i] = 1;
        for(int val = roomSize[i]; val <= area; ++val){
            if(vis[val - roomSize[i]]){
                dp[val] = max(dp[val], dp[val - roomSize[i]] + cur);
                vis[val] = true;
            }
        }
    }
    return dp[area][1];
}

 
void solve() {
    vector<int> roomSize(4);
    for(int &elem: roomSize){
        cin >> elem;
    }
    vector<int> tmp = roomSize;
    sort(roomSize.rbegin(), roomSize.rend());
    vector<int> mp(4);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(roomSize[i] == tmp[j]){
                mp[j] = i;
            }
        }
    }


    int x, y;
    cin >> x >> y;


    vector<int> v1, v2;

    v1 = get(x, roomSize);
    v2 = get(x + y, roomSize);

    v1 = v1 - v2;

    for(int i = 0; i < 3; ++i){
        cout << v1[mp[i]] << ' ';
    }
    cout << v1[mp[3]];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
