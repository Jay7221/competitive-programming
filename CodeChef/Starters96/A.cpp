#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    auto check = [&](int ind){
        return (max(ind, n - 1 - ind) >= k);
    };
    priority_queue<int> pq;
    for(int i = n - 1; i >= 0; --i){
        if(check(i)){
            pq.push(a[i]);
        }
    }
    for(int i = n - 1; i >= 0; --i){
        if(check(i)){
            a[i] = pq.top();
            pq.pop();
        }
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << ' ';
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
