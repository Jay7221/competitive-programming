#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = (1 << 15);
vector<int> pals;
void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> freq(MAX);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        ++freq[a];
        for(int pal : pals){
            int x = a ^ pal;
            if(x < MAX){
                ans += freq[x];
            }
        }
    }
    cout << ans << '\n';
}
void pre(){
    for(int x = 0; x < MAX; ++x){
        vector<int> v;
        int k = x;
        while(k > 0){
            v.push_back(k % 10);
            k /= 10;
        }
        vector<int> v2 = v;
        reverse(v.begin(), v.end());
        if(v == v2){
            pals.push_back(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
