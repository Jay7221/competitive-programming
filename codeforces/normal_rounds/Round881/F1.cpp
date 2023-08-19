#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;

    vector<int> mn(n + 1), mx(n + 1);
    vector<int> dp_mn(n + 1), dp_mx(n + 1);
    mn[0] = dp_mn[0] = 0;
    mx[0] = dp_mx[0] = 1;

    int u = 1;
    for(int i = 0; i < n; ++i){
        char ch;
        cin >> ch;
        if(ch == '+'){
            int v, x;
            cin >> v >> x;
            --v;

            dp_mn[u] = x + min(dp_mn[v], 0);
            dp_mx[u] = x + max(dp_mx[v], 0);
            mn[u] = min(dp_mn[u], mn[v]);
            mx[u] = max(dp_mx[u], mx[v]);

            ++u;
        }else{
            int u, v, k;
            cin >> u >> v >> k;
            bool flag;
            --u, --v;
            if((mn[v] <= k) && (k <= mx[v])){
                flag = true;
            }else{
                flag = false;
            }
            if(flag){
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
