#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
const int MASK = (1 << 10);
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        int cur = 1;
        while(!s.empty()){
            if(s.back() == '1'){
                b[i] += cur;
            }
            cur <<= 1;
            s.pop_back();
        }
    }
    vector<ll> dp(MASK, INF);
    for(int i = 0; i < n; ++i){
        dp[b[i]] = a[i];
    }
    for(int mask = 0; mask < MASK; ++mask){
        if(dp[mask] < INF){
            for(int i = 0; i < n; ++i){
                int new_mask = mask | b[i];
                dp[new_mask] = min(dp[new_mask], dp[mask] + a[i]);
            }
        }
    }
    int x = 0;
    for(int i = 0; i < n; ++i){
        x |= b[i];
    }
    cout << dp[x] << '\n';
}
int main(){
    solve();
    return 0;
}
