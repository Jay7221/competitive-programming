#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    auto check = [&](int i, int j){
        return ((i >= 0) && (j >= 0) && (i < n) && (j < m) && (s[i][j] == '#'));
    };
    int x, y;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(check(i, j)){
                continue;
            }
            int tmp = 0;
            for(auto [dx, dy] : d){
                tmp += check(i + dx, j + dy);
            }
            if(tmp >= 2){
                x = i, y = j;
            }
        }
    }
    cout << (x + 1) << ' ' << (y + 1) << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}
