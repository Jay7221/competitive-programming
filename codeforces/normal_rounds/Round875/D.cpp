#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    vector<vector<int>> v(n + 1);
    for(int i = 0; i < n; ++i){
        v[a[i]].push_back(b[i]);
    }
    vector<int> freq(2 * n + 1);
    ll ans = 0;

    for(int ai = 1; (ai * ai <= 2 * n) && (ai <= n); ++ai){
        for(int bi : v[ai]){
            if(ai * ai - bi >= 0){
                ans += freq[ai * ai - bi];
            }
            ++freq[bi];
        }
        for(int aj = ai + 1; (ai * aj <= 2 * n) && (aj <= n); ++aj){
            for(int bj : v[aj]){
                if(ai * aj - bj >= 0){
                    ans += freq[ai * aj - bj];
                }
            }
        }
        for(int bi : v[ai]){
            --freq[bi];
        }
    }
    cout << ans << '\n';
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
