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
 
 
ll solve() {
    ll n, c, s, m;
    cin >> n >> c >> s >> m;
    vector<ll> w(n);
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }

    if(m >= accumulate(w.begin(), w.end(), 0ll)){
        return n * c;
    }

    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>, greater<pair<ll, ll>>> left;
    priority_queue<pair<ll, ll>> right;

    int l = -1;
    ll totweight = 0;

    while(totweight <= m){
        ++l;
        totweight += w[l];
        left.push({w[l], l});
    }
    for(int i = l + 1; i < n; ++i){
        right.push({w[i], i});
    }

    ll ans = l * c;
    ll cost = ans;
    vector<bool> flip(n);

    // basically we calculate the cost for array a[0:l -1]
    while(l > 0){
        totweight -= w[l];
        right.push({w[l], l});
        cost -= c;
        if(flip[l]){
            cost -= s;
        }
        --l;

        while(totweight <= m){
            while(left.top().second > l){
                left.pop();
            }
            if(left.top().first >= right.top().first){
                break;
            }
            int i = left.top().second;
            int j = right.top().second;
            left.pop(), right.pop();

            totweight -= w[i];

            swap(w[i], w[j]);
            flip[i] = true;
            left.push({w[i], i});
            right.push({w[j], j});
            cost += s;

            totweight += w[i];
        }

        if(totweight > m){
            ans = min(ans, cost);
        }
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
