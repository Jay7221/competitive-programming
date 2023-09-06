#include <bits/stdc++.h>
 
using namespace std;
 
 
#define ll long long

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

    T solve()
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

const ll INF = 1e9 + 7;
ll connectTwoGroups(vector<vector<ll>>& cost) {
    vector<ll> Lmin(cost.size());
    vector<ll> Rmin(cost[0].size());
    ll ans = 0;
    for(ll i = 0; i < (ll)cost.size();++i) {
        Lmin[i] = INF;
        for(ll j = 0; j < (ll)Rmin.size(); ++j) {
            Lmin[i] = min(Lmin[i], cost[i][j]);
        }
        ans += Lmin[i];
    }
    for(ll j = 0; j < (ll)Rmin.size();++j) {
        Rmin[j] = INF;
        for(ll i = 0; i < (ll)Lmin.size(); ++i) {
            Rmin[j] = min(Rmin[j],cost[i][j]);
        }
        ans += Rmin[j];
    }
    hungarian<ll> H(Lmin.size(),Rmin.size());
    for(ll i = 0; i < (ll)Lmin.size(); ++i) {
        for(ll j = 0; j < (ll)Rmin.size(); ++j) {
            H.addEdge(i,j,-1*(cost[i][j]-Lmin[i]-Rmin[j]));
        }
    }
    ll ret = H.solve();
    ans = ans - ret;
    return ans;
}

void solve() {
    ll n, m;
    cin >> n;
    vector<ll> c(n), f(n), p(n);
    for(ll i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(ll i = 0; i < n; ++i){
        cin >> f[i];
    }
    for(ll i = 0; i < n; ++i){
        cin >> p[i];
    }
    cin >> m;
    vector<ll> oc(m), of(m), op(m);
    for(ll i = 0; i < m; ++i){
        cin >> oc[i];
    }
    for(ll i = 0; i < m; ++i){
        cin >> of[i];
    }
    for(ll i = 0; i < m; ++i){
        cin >> op[i];
    }

    vector<vector<ll>> cost(n, vector<ll>(m));
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < m; ++j){
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
 
