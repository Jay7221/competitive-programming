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
 
int get(int r){
    if(r <= 0){
        return 0;
    }
    int l = (r >> 2) << 2;
    int ans = 0;
    for(int i = l; i <= r; ++i){
        ans ^= i;
    }
    return ans;
};
int get(int l, int r){
    if(l > r){
        return 0;
    }
    return get(l - 1) ^ get(r);
}
int get(int l, int r, bool include_first){
    if(!include_first){
        ++l;
    }
    if((l & 1) != (r & 1)){
        --r;
    }
    if(l > r){
        return 0;
    }
    int ans = get(l >> 1, r >> 1) << 1;
    if(l & 1){
        int len = (r - l + 2) >> 1;
        if(len & 1){
            ans ^= 1;
        }
    }
    return ans;
}

void test(){
    for(int i = 0; i < 100; ++i){
        int cur = 0;
        int cur0 = 0, cur1 = 0;
        bool inc = true;
        for(int j = i; j < 100; ++j){
            cur ^= j;
            assert(cur == get(i, j));

            if(inc){
                cur0 ^= j;
            }
            else{
                cur1 ^= j;
            }

            assert(cur0 == get(i, j, true));
            assert(cur1 == get(i, j, false));

            inc ^= 1;

        }
    }

}
 
void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, int>> v;
    vector<pair<int, int>> corners = {
        {1, 1},
        {1, m},
        {n, 1},
        {n, m}
    };
    vector<pair<int, int>> edges = {
        {1, y},
        {x, m},
        {n, y},
        {x, 1}
    };
    for(auto [xx, yy]: corners){
        v.push_back({
            abs(x - xx) + abs(y - yy),
            0
        });
    }
    for(auto [xx, yy]: edges){
        v.push_back({
            abs(x - xx) + abs(y - yy),
            1
        });
    }

    sort(v.begin(), v.end());

    bool include = false;
    bool corner = false;
    int ans = 0;
    int prev = 0;
    for(auto [p, f]: v){
        if(corner){
            ans ^= get(prev, p, include);
            include ^= (p - prev + 1) & 1;
        }
        else if(include){
            ans ^= get(prev, p);
        }

        prev = p + 1;

        if(f == 1){
            include ^= 1;
        }
        else{
            corner ^= 1;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    test();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
