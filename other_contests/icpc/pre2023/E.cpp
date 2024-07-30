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
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b, --c;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> type(n);
    // type[0] => unoccupied
    // type[1] => A
    // type[2] => B
    // type[3] => C

    type[a] = 1;
    type[b] = 2;
    type[c] = 3;
    vector<int> num = {n - 3, 1, 1, 1};
    vector<int> qa, qb, qc;
    qa.push_back(a);
    qb.push_back(b);
    qc.push_back(c);

    auto get = [](int a, int b){
        if(a > b){
            swap(a, b);
        }
        if((b == 3) && (a == 1)){
            return a;
        }
        return b;
    };
    auto isActive = [&](int u){
        for(int v : adj[u]){
            if((type[v] != type[u]) && (get(type[v], type[u]) == type[u])){
                return true;
            }
        }
        return false;
    };
    auto expand = [&](vector<int> arr){
        vector<int> ans;
        for(int u : arr){
            ans.push_back(u);
            for(int v : adj[u]){
                if((type[u] != type[v]) && (get(type[u], type[v]) == type[u])){
                    ans.push_back(v);
                    --num[type[v]];
                    ++num[type[u]];
                    type[v] = type[u];
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    };
    auto contract = [&](vector<int> arr, int t){
        vector<int> ans;
        for(int u : arr){
            if((type[u] == t) && isActive(u)){
                ans.push_back(u);
            }
        }
        return ans;
    };

    int cnt = 0;


    while(min({num[1], num[2], num[3]}) > 0){
        vector<int> pa, pb, pc;
        pa = qa, pb = qb, pc = qc;

        qa = contract(qa, 1);
        qa = expand(qa);

        qb = contract(qb, 2);
        qb = expand(qb);

        qc = contract(qc, 3);
        qc = expand(qc);

        if((pa == qa) && (pb == qb) && (pc == qc)){
            break;
        }
    }
    if(num[1] == 0){
        cout << "B\n";
    }
    else if(num[2] == 0){
        cout << "C\n";
    }
    else if(num[3] == 0){
        cout << "A\n";
    }
    else{
        cout << "DRAW\n";
    }
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
 
