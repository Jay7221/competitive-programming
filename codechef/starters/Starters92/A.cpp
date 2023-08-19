#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        int m, L;
        cin >> m >> L;
        if(L == l){
            pq.push(m);
        }
    }
    int ans = 0;
    if(pq.size() >= k){
        while(k--){
            ans += pq.top();
            pq.pop();
        }
    }else{
        ans = -1;
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
