#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> a(n), d(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> d[i];
    }
    ll ans = accumulate(d.begin(), d.end(), 0ll);
    sort(a.begin(), a.end());
    for(int i = 1; i < n; ++i){
        a[i] += a[i - 1];
    }
    for(int i = 0; i < n; ++i){
        ans -= a[i];
    }
    cout << ans << '\n';
}
