#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int na = count(v.begin(), v.end(), "A");
    int nb = count(v.begin(), v.end(), "B");
    int nab = count(v.begin(), v.end(), "AB");
    int no = count(v.begin(), v.end(), "O");
    int ans = no + nab + max(na, nb);
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
