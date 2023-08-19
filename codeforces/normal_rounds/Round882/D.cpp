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
 
struct MinSeg{
    vector<int> tree;
    const int INF = 1e9 + 7;
    int n;
    MinSeg(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree.assign(2 * n, INF);
    }
    void update(int l, int r, int val){
        l += n;
        r += n;
        while(l <= r){
            if(l & 1){
                tree[l] = min(tree[l], val);
                ++l;
            }
            if(!(r & 1)){
                tree[r] = min(tree[r], val);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
    }
    int get(int ind){
        ind += n;
        int ans = INF;
        while(ind > 0){
            ans = min(ans, tree[ind]);
            ind >>= 1;
        }
        return ans;
    }
};
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<int> f(n);
    MinSeg st(n);
    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        --l, --r;
        st.update(l, r, i);
    }
    for(int i = 0; i < n; ++i){
        f[i] = st.get(i);
    }
    vector<pair<int, int>> tmp;
    for(int i = 0; i < n; ++i){
        tmp.push_back({f[i], i});
    }
    sort(tmp.begin(), tmp.end());
    vector<int> indexOf(n);
    for(int i = 0; i < n; ++i){
        indexOf[tmp[i].second] = i;
    }

    string b = s;
    for(int i = 0; i < n; ++i){
        b[indexOf[i]] = s[i];
    }
    s = b;

    int noActive = 0;
    for(int i = 0; i < n; ++i){
        noActive += (f[i] < INF);
    }

    int noOne = count(s.begin(), s.end(), '1');
    int k = min(noOne, noActive);
    int ans = 0;
    for(int i = 0; i < k; ++i){
        ans += (s[i] == '0');
    }

    while(q--){
        int ind;
        cin >> ind;
        --ind;
        ind = indexOf[ind];
        if(s[ind] == '1'){
            s[ind] = '0';
            --noOne;
            if(ind < k){
                ++ans;
            }
            if(k > min(noActive, noOne)){
                if(s[k - 1] == '0'){
                    --ans;
                }
                --k;
            }
        }else{
            s[ind] = '1';
            ++noOne;
            if(ind < k){
                --ans;
            }
            if(k < min(noActive, noOne)){
                ++k;
                if(s[k - 1] == '0'){
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
