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
 
struct LazySegmentTree{
    int n;
    vector<ll> L, R;

    vector<ll> sum;

    vector<ll> propVal;
    vector<bool> prop;

    LazySegmentTree(int sz){
        n = 4 * sz;
        L = vector<ll>(n);
        R = vector<ll>(n);

        sum = vector<ll>(n);

        prop = vector<bool>(n);
        propVal = vector<ll>(n);

        n >>= 1;
        init(1, 0, sz - 1);
    }
    void init(int node, int l, int r){
        if(l > r){
            return;
        }
        L[node] = l;
        R[node] = r;
        if(l < r){
            int mid = (l + r) / 2;
            init(2 * node, l, mid);
            init(2 * node + 1, mid + 1, r);
        }
    }
    void propogate(int node){
        if(prop[node]){
            prop[node] = false;
            int left = 2 * node;
            int right = 2 * node + 1;

            propVal[left] = propVal[node];
            propVal[right] = propVal[node];
            prop[left] = true;
            prop[right] = true;

            sum[left] = (R[left] - L[left] + 1) * propVal[left];
            sum[right] = (R[right] - L[right] + 1) * propVal[right];
        }
    }

    void set(int node, int l, int r, ll x){
        if((r < L[node]) || (R[node] < l)) {
            return;
        }
        if((l <= L[node]) && (R[node] <= r)){
            sum[node] = (R[node] - L[node] + 1) * x;
            propVal[node] = x;
            prop[node] = true;
        }else{
            propogate(node);

            set(2 * node, l, r, x);
            set(2 * node + 1, l, r, x);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
        }
    }
    ll get(int node, int l, int r){
        if((l <= L[node]) && (R[node] <= r)){
            return sum[node];
        }
        propogate(node);
        ll ans = 0;
        if(l <= R[2 * node]){
            ans += get(2 * node, l, r);
        }
        if(L[2 * node + 1] <= r){
            ans += get(2 * node + 1, l, r);
        }
        return ans;
    }
};

vector<ll> solve_suboptimal(int n, vector<vector<int>> &queries){
    LazySegmentTree tree(n + 1);
    vector<ll> res;
    for(vector<int> &query: queries){
        int l = query[0];
        int r = query[1];
        int x = query[2];
        res.push_back(tree.get(1, l, r));
        tree.set(1, l, r, x);
    }
    return res;
}

vector<ll> brute(int n, vector<vector<int>> &queries){
    vector<int> arr(n + 1);
    vector<ll> res;
    for(vector<int> &query: queries){
        int l = query[0];
        int r = query[1];
        int x = query[2];
        ll sum = 0;
        for(int i = l; i <= r; ++i){
            sum += arr[i];
            arr[i] = x;
        }
        res.push_back(sum);
    }
    return res;
}
 
vector<ll> solve(int n, vector<vector<int>> &queries) {
    map<int, int> mp;
    mp[0] = 0;
    vector<ll> res;
    for(vector<int> &query: queries){
        int l = query[0];
        int r = query[1];
        int x = query[2];

        auto it = mp.lower_bound(l);
        --it;

        ll lastVal = it -> second;
        ll sum = (r - l + 1) * 1ll * lastVal;

        while(true){
            auto it = mp.lower_bound(l);
            if(it == mp.end()){
                break;
            }
            int ind = it -> first;
            if(ind > r + 1){
                break;
            }
            sum -= (r - ind + 1) * lastVal;
            lastVal = it -> second;
            sum += (r - ind + 1) * lastVal;
            mp.erase(it);
        }

        mp[l] = x;
        mp[r + 1] = lastVal;

        res.push_back(sum);

    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q, vector<int>(3));
    for(int i = 0; i < q; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> queries[i][j];
        }
    }

    //assert(solve(n, queries) == brute(n, queries));
    //assert(solve(n, queries) == solve_suboptimal(n, queries));

    for(ll elem: solve(n, queries)){
        cout << elem << '\n';
    }
    
    return 0;
}
 
