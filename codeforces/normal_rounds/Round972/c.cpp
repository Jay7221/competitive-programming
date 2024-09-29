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
 
int getVal(char ch){
    switch(ch){
        case 'n': return 0;
        case 'a': return 1;
        case 'r': return 2;
        case 'e': return 3;
        case 'k': return 4;
    }
    return -1;
}

vector<int> getValueArr(string s){
    vector<int> a;
    for(char ch: s){
        int val = getVal(ch);
        if(val != -1){
            a.push_back(val);
        }
    }
    return a;
}
 
void solve() {
    int n, m;
    cin >> n >> m;

    // dp[i] = the max score such the next value must be i
    vector<int> dp(5, INT_MIN);
    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        vector<int> a = getValueArr(s);

        vector<int> ndp = dp;

        for(int start = 0; start < 5; ++start){
            if(dp[start] == INT_MIN){   // can't start with this char yet
                continue;
            }
            int score = dp[start];
            int cur = start;
            for(int val: a){
                --score;
                if(cur == val){
                    ++cur;
                }
                if(cur == 5){
                    score += 10;
                    cur = 0;
                }
            }
            ndp[cur] = max(ndp[cur], score);
        }
        dp = ndp;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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
 
