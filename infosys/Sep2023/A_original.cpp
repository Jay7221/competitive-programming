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
 

template <typename T>
struct hungarian
{ // km
    int n;
    vector<int> matchx;
    vector<int> matchy;
    vector<int> pre;
    vector<bool> visx;
    vector<bool> visy;
    vector<T> lx;
    vector<T> ly;
    vector<vector<T>> g;
    vector<T> slack;
    T inf;
    T res;
    queue<int> q;
    int org_n;
    int org_m;

    hungarian(int _n, int _m)
    {
        org_n = _n;
        org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<T>::max();
        res = 0;
        g = vector<vector<T>>(n, vector<T>(n));
        matchx = vector<int>(n, -1);
        matchy = vector<int>(n, -1);
        pre = vector<int>(n);
        visx = vector<bool>(n);
        visy = vector<bool>(n);
        lx = vector<T>(n, -inf);
        ly = vector<T>(n);
        slack = vector<T>(n);
    }

    void addEdge(int u, int v, int w)
    {
        g[u][v] = max(w, 0); 
    }

    bool check(int v)
    {
        visy[v] = true;
        if (matchy[v] != -1)
        {
            q.push(matchy[v]);
            visx[matchy[v]] = true;
            return false;
        }
        while (v != -1)
        {
            matchy[v] = pre[v];
            swap(v, matchx[pre[v]]);
        }
        return true;
    }

    void bfs(int i)
    {
        while (!q.empty())
        {
            q.pop();
        }
        q.push(i);
        visx[i] = true;
        while (true)
        {
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; v++)
                {
                    if (!visy[v])
                    {
                        T delta = lx[u] + ly[v] - g[u][v];
                        if (slack[v] >= delta)
                        {
                            pre[v] = u;
                            if (delta)
                            {
                                slack[v] = delta;
                            }
                            else if (check(v))
                            {
                                return;
                            }
                        }
                    }
                }
            }
            T a = inf;
            for (int j = 0; j < n; j++)
            {
                if (!visy[j])
                {
                    a = min(a, slack[j]);
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (visx[j])
                { // S
                    lx[j] -= a;
                }
                if (visy[j])
                { // T
                    ly[j] += a;
                }
                else
                { // T'
                    slack[j] -= a;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (!visy[j] && slack[j] == 0 && check(j))
                {
                    return;
                }
            }
        }
    }

    int solve()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                lx[i] = max(lx[i], g[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            fill(slack.begin(), slack.end(), inf);
            fill(visx.begin(), visx.end(), false);
            fill(visy.begin(), visy.end(), false);
            bfs(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (g[i][matchx[i]] > 0)
            {
                res += g[i][matchx[i]];
            }
            else
            {
                matchx[i] = -1;
            }
        }
        return res;
    }
};

#define getL(x) (x+2)
#define getR(x) (2+Lmin.size()+x) 

int connectTwoGroups(vector<vector<int>>& cost) {
    vector<int> Lmin(cost.size());
    vector<int> Rmin(cost[0].size());
    int ans = 0;
    for(int i = 0; i < cost.size();++i) {
        Lmin[i] = INT_MAX;
        for(int j = 0; j < Rmin.size(); ++j) {
            Lmin[i] = min(Lmin[i], cost[i][j]);
        }
        ans += Lmin[i];
    }
    for(int j = 0; j < Rmin.size();++j) {
        Rmin[j] = INT_MAX;
        for(int i = 0; i < Lmin.size(); ++i) {
            Rmin[j] = min(Rmin[j],cost[i][j]);
        }
        ans += Rmin[j];
    }
    hungarian<int> H(Lmin.size(),Rmin.size());
    for(int i = 0; i < Lmin.size(); ++i) {
        for(int j = 0; j < Rmin.size(); ++j) {
            H.addEdge(i,j,-1*(cost[i][j]-Lmin[i]-Rmin[j]));
        }
    }
    int ret = H.solve();
    ans = ans - ret;
    return ans;
}


#define order tuple<ll, ll, ll>
 
void solve() {
    int n, m;
    cin >> n;
    vector<int> c(n), f(n), p(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> f[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    cin >> m;
    vector<int> oc(m), of(m), op(m);
    for(int i = 0; i < m; ++i){
        cin >> oc[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> of[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> op[i];
    }

    vector<vector<int>> cost(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if((c[i] >= oc[j]) && (f[i] >= of[j])){
                cost[i][j] = max(cost[i][j], op[j] - p[i]);
            }
        }
    }
    cout << connectTwoGroups(cost) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}
 
