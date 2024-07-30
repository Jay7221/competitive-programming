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
 

ll countPageFaults(ll k, const vector<ll>& a) {
    ll pageFaults = 0;
    unordered_map<ll, ll> nextPageIndex; // Map to store the index of the next occurrence of each page
    vector<ll> cache(k, -1); // Cache to store the pages, initialized with -1 indicating empty slots

    for (ll i = 0; i < a.size(); ++i) {
        ll page = a[i];
        
        // Update the index of the next occurrence of the current page
        nextPageIndex[page] = numeric_limits<ll>::max(); // Initialize with a large value
        for (ll j = i + 1; j < a.size(); ++j) {
            if (a[j] == page) {
                nextPageIndex[page] = j;
                break;
            }
        }

        // If page is not in cache
        if (find(cache.begin(), cache.end(), page) == cache.end()) {
            // If cache is full, find the page in cache with the farthest next occurrence index
            if (cache.size() == k) {
                ll farthestIndex = -1;
                ll pageToReplace = -1;
                for (ll j = 0; j < cache.size(); ++j) {
                    if (nextPageIndex[cache[j]] > farthestIndex) {
                        farthestIndex = nextPageIndex[cache[j]];
                        pageToReplace = j;
                    }
                }
                cache[pageToReplace] = page; // Replace the page with the farthest next occurrence index
            } else {
                cache.push_back(page); // Add page to cache
            }
            pageFaults++;
        }
    }

    return pageFaults;
}
 
void solve() {
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    if(countPageFaults(n, a) > t){
        cout << -1 << '\n';
        return;
    }

    if(n <= t){
        cout << 0 << '\n';
        return;
    }

    ll l = 1, r = n;
    while(l < r){
        ll m = (l + r) >> 1;
        if(countPageFaults(m, a) > t){
            l = m + 1; }
        else{
            r = m;
        }
    }
    cout << l << '\n';
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
 
