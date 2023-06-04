#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int INF = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> cost(n, vector<int>(3, 1));
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R'){
            cost[i][0] = 0;
        }else if(s[i] == 'P'){
            cost[i][1] = 0;
        }else{
            cost[i][2] = 0;
        }
    }
    auto calc = [&](){
        vector<vector<int>> dp(n, vector<int>(3, INF));
        for(int i = 0; i < 3; ++i){
            dp[0][i] = cost[0][i];
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    if(j != k){
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);
                    }
                }
            }
        }
        return dp[n - 1];
    };
    int ans = INF;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j< 3; ++j){
            if(i != j){
                cost[0][j] += INF;
            }
        }
        vector<int> dp = calc();
        for(int j = 0; j< 3; ++j){
            if(i != j){
                cost[0][j] -= INF;
            }
        }
        for(int j = 0; j < 3; ++j){
            if(i != j){
                ans = min(ans, dp[j]);
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
