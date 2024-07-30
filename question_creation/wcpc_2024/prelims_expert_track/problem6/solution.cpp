#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9+7;
 
int main()
{
    fast;
    ll n, a, b;
    cin >> n >> a >> b;

    assert(n >= a);
 
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = x + pref[i-1];
    }
 
    ll ans = -1e18;
    multiset<ll> ms;
 
    for (int i = a; i <= n; i++) {
        if (i > b) {
            ms.erase(ms.find(pref[i - b - 1]));
        }
        ms.insert(pref[i - a]);
        ans = max(ans, pref[i] - *ms.begin());
    }
    
    cout << ans << endl;
 
    return 0;
}
