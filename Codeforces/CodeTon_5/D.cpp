#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18 + 7;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; ++i){
        int u, v, y;
        cin >> u >> v >> y;
        --u, --v;
        graph[u].push_back({v, y});
        graph[v].push_back({u, y});
    }
    string s;
    for(int i = 0; i < n; ++i){
        s.push_back('1');
    }

    vector<pair<string, ll>> groups;
    ll time = 0;
    vector<ll> d(n, INF);
    d[n - 1] = 0;
    
    set<pair<ll, int>> st;
    vector<bool> vis(n);
    st.insert({0, n - 1});

    while(st.size()){
        ll t;
        int u;
        tie(t, u) = *st.begin();
        st.erase(st.begin());
        if(u != n - 1){
            groups.push_back({s, t - time});
        }
        vis[u] = true;
        s[u] = '0';
        time = t;
        if(u == 0){
            break;
        }

        for(auto [v, w] : graph[u]){
            if(!vis[v]){
                if(d[v] > t + w){
                    st.erase({d[v], v});
                    d[v] = t + w;
                    st.insert({d[v], v});
                }
            }
        }
    }


    if(s[0] == '1'){
        cout << "inf\n";
    }else{
        cout << time << ' ' << groups.size() << '\n';
        for(auto [s, t] : groups){
            cout << s << ' ' << t << '\n';
        }
    }
    /*
    */
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
