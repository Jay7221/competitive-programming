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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> ranges;
    vector<vector<int>> rainIndex(n + 2);
    for(ll i = 0; i < m; ++i){
        ll l, r;
        cin >> l >> r;
        rainIndex[l].push_back(i + 1);
        rainIndex[r + 1].push_back(-(i + 1));
        ranges.push_back({l, r});
    }

    vector<ll> arr(n + 2), pre1(n + 2), pre2(n + 2);
    for(auto [l, r] : ranges){
        ++arr[l];
        --arr[r + 1];
    }
    for(ll i = 1; i <= n; ++i){
        arr[i] += arr[i - 1];
    }

    for(ll i = 1; i <= n; ++i){
        pre1[i] = (arr[i] == 1) + pre1[i - 1];
        pre2[i] = (arr[i] == 2) + pre2[i - 1];
    }

    set<int> rain;
    set<pair<int, int>> overlapRanges;
    for(int i = 1; i <= n + 1; ++i){
        for(int ind : rainIndex[i]){
            if(ind > 0){
                rain.insert(ind);
            }
            else{
                rain.erase(-ind);
            }
        }
        if(rain.size() == 2){
            int ind1 = *rain.begin();
            rain.erase(ind1);
            int ind2 = *rain.begin();
            rain.insert(ind1);
            overlapRanges.insert({ind1, ind2});
        }
    }

    int mx1 = 0, mx2 = 0;
    for(auto [l, r] : ranges){
        int dryDays = pre1[r] - pre1[l - 1];
        if(mx1 < dryDays){
            mx2 = mx1;
            mx1 = dryDays;
        }
        else if(mx2 < dryDays){
            mx2 = dryDays;
        }
    }
    int ans = mx1 + mx2;
    for(auto [i, j] : overlapRanges){
        --i, --j;
        int l1, r1, l2, r2;
        tie(l1, r1) = ranges[i];
        tie(l2, r2) = ranges[j];
        int l_mn = min(l1, l2), l_mx = max(l1, l2);
        int r_mn = min(r1, r2), r_mx = max(r1, r2);
        int val1 = pre1[r_mx] - pre1[l_mn - 1];
        int val2 = pre2[r_mn] - pre2[l_mx - 1];
        ans = max(ans, val1 + val2);
    }
    int val0 = count(arr.begin() + 1, arr.begin() + n + 1, 0);
    ans += val0;
    cout << ans << '\n';
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
 
