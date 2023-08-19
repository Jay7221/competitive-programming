#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            v[i][j] = i * m + j + 1;
        }
    }
    if(m % 2 == 1){
        if(n % 2 == 1){
            vector<vector<int>> a(n);
            int cur = 0;
            for(int i = 0; i < n; i += 2){
                a[i] = v[cur];
                ++cur;
            }
            for(int i = 1; i < n; i += 2){
                a[i] = v[cur];
                ++cur;
            }
            v = a;
        }else{
            int cur = 1;
            for(int j = 0; j < m; ++j){
                for(int i = 0; i < n; ++i){
                    v[i][j] = cur;
                    ++cur;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
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
