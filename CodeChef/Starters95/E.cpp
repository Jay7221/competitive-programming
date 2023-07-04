#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = 1 - a[i];
    }

    vector<ll> dp(n);
    dp[0] = a[0];
    stack<ll> st, stdp;
    st.push(a[0]);
    stdp.push(0);
    multiset<ll> s;

    s.insert(st.top() + stdp.top());
    for(int i = 1; i < n; ++i){
        ll tmp = dp[i - 1];
        while((st.size() > 0) && (a[i] <= st.top())){
            s.erase(s.find(st.top() + stdp.top()));
            st.pop();
            tmp = max(tmp, stdp.top());
            stdp.pop();
        }
        st.push(a[i]);
        stdp.push(tmp);

        s.insert(st.top() + stdp.top());

        dp[i] = *(--s.end());
    }
    cout << dp[n - 1] << '\n';
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
