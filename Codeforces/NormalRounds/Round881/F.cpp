#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info{
    int sum, minPrefL, maxPrefL, minPrefR, maxPrefR, minSeg, maxSeg;

    info(int el = 0){
        sum = el;
        minSeg = minPrefL = minPrefR = min(el, 0);
        maxSeg = maxPrefL = maxPrefR = max(el, 0);
    }
};
info merge(info &a, info &b){
    info res;
    res.sum = a.sum + b.sum;

    res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
    res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);

    res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
    res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);

    res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
    res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});

    return res;
}

const int LOGMAX = 20;
void solve(){
    int n;
    cin >> n;
    
    vector<vector<int>> par(n + 1, vector<int>(LOGMAX));
    vector<vector<info>> ans(n + 1, vector<info>(LOGMAX));
    vector<int> depth(n + 1);
    ans[0][0] = info(1);

    int cur = 0;
    for(int q = 0; q < n; ++q){
        char ch;
        cin >> ch;
        if(ch == '+'){
            int v, x;
            cin >> v >> x;
            --v;
            ++cur;

            depth[cur] = depth[v] + 1;

            par[cur][0] = v;
            ans[cur][0] = info(x);
            for(int k = 0; k < LOGMAX - 1; ++k){
                par[cur][k + 1] = par[par[cur][k]][k];
                ans[cur][k + 1] = merge(ans[cur][k], ans[par[cur][k]][k]);
            }

        }else{
            int u, v, x;
            cin >> u >> v >> x;
            --u, --v;

            if(depth[u] < depth[v]){
                swap(u, v);
            }

            info a, b;
            int diff = depth[u] - depth[v];
            for(int k = LOGMAX - 1; k >= 0; --k){
                if((diff >> k) & 1){
                    a = merge(a, ans[u][k]);
                    u = par[u][k];
                }
            }
            if(u == v){
                a = merge(a, ans[u][0]);
            }
            else{
                for(int k = LOGMAX - 1; k >= 0; --k){
                    if(par[u][k] != par[v][k]){
                        a = merge(a, ans[u][k]);
                        b = merge(b, ans[v][k]);
                        u = par[u][k];
                        v = par[v][k];
                    }
                }
                a = merge(a, ans[u][1]);
                b = merge(b, ans[v][0]);
            }

            swap(b.minPrefL, b.minPrefR);
            swap(b.maxPrefL, b.maxPrefR);

            info res = merge(a, b);
            if((res.minSeg <= x) && (x <= res.maxSeg)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
