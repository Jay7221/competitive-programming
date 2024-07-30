#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve_brute(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<ll> cost(n);
    for(int i = 0; i < n; ++i){
        ll cur = 0;
        for(int j = i; j < n; ++j){
            cur += a[j];
            cost[i] = max(cost[i], abs(cur));
        }
        cost[i] = cost[i] * cost[i];
    }
    for(int i = 0; i < n; ++i){
        cout << cost[i] << ' ';
    }
    cout << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }

    vector<ll> cost(n + 1);
    int mx = pre[n], mn = pre[n];
    for(int i = n; i > 0; --i){
        mx = max(mx, pre[i]);
        mn = min(mn, pre[i]);
        cost[i] = max(abs(mx - pre[i - 1]),
                      abs(pre[i - 1] - mn));
        cost[i] = cost[i] * cost[i];
    }
    for(int i = 1; i <= n; ++i){
        cout << cost[i] << ' ';
    }
    cout << '\n';
}
int main(){
    bool brute = false;
    int t;
    cin >> t;
    while(t--){
        if(brute){
            solve_brute();
        }
        else{
            solve();
        }
    }
}
