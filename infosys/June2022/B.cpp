#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        st.insert(a);
    }
    ll ans = st.size();
    ans = (ans * ans) % MOD;
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
