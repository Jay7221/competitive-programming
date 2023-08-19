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
 
vector<vector<int>> getCycles(vector<int> &p){
    int n = p.size();
    vector<bool> vis(n);
    vector<int> ind(n);

    for(int i = 0; i < n; ++i){
        --p[i];
        ind[p[i]] = i;
    }

    vector<vector<int>> cycles;
    for(int i = 0; i < n; ++i){
        if(vis[i]){
            continue;
        }
        int cur = i;
        vector<int> c;
        while(!vis[cur]){
            vis[cur] = true;
            c.push_back(cur);
            cur = ind[cur];
        }
        cycles.push_back(c);
    }
    for(auto &c : cycles){
        for(auto &ind : c){
            ++ind;
        }
    }
    return cycles;
}
 
vector<vector<int>> solve(vector<int> &p, int k) {
    int n = p.size();
    vector<vector<int>> ans;
    // all cycles cycles
    vector<vector<int>> cycles = getCycles(p);

    // req cycles
    int req_cycles = n - k;
    int no_cycles = cycles.size();
    if(req_cycles < no_cycles){
        ll diff = cycles.size() - req_cycles;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto c : cycles){
            pq.push(c.front());
        }
        while(diff--){
            int u = pq.top();
            pq.pop();
            int v = pq.top();
            pq.pop();
            ans.push_back({u, v});
            pq.push(u);
        }
    }
    else if(req_cycles > no_cycles){
        while(!cycles.empty()){
            vector<int> c = cycles.back();
            cycles.pop_back();
            if(c.size() == 1){
                continue;
            }
            if(c.size() == 2){
                ans.push_back({c[0], c[1]});
                continue;
            }
            int mn_ind = min_element(c.begin() + 1, c.end()) - c.begin();
            ans.push_back({c[0], c[mn_ind]});
            vector<int> c1, c2;
            c1.push_back(c[0]);
            for(int i = mn_ind + 1; i < no_cycles; ++i){
                c1.push_back(c[i]);
            }
            c2.push_back(c[mn_ind]);
            for(int i = 1; i < mn_ind; ++i){
                c2.push_back(c[i]);
            }
            cycles.push_back(c1);
            cycles.push_back(c2);
        }
        int diff = req_cycles - no_cycles;
        sort(ans.begin(), ans.end());
        ans.resize(diff);
    }
    if(ans.empty()){
        ans = {{-1, -1}};
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    for(auto v : solve(p, k)){
        cout << v[0] << ' ' << v[1] << '\n';
    }
    
    return 0;
}
 
