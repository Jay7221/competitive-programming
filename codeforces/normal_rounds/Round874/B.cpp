#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v[i] = {a[i], i};
    }
    for(int j = 0; j < n; ++j){
        cin >> b[j];
    }
    sort(b.begin(), b.end());
    sort(v.begin(), v.end());
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        int val, ind;
        tie(val, ind) = v[i];
        c[ind] = b[i];
    }
    for(int i = 0; i < n; ++i){
        cout << c[i] << ' ' ;
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
