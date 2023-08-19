#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> freq(n + 1);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++freq[x];
    }
    vector<int> mn = freq;
    for(int i = 1; i <= n; ++i){
        mn[i] = min(mn[i], mn[i - 1]);
    }
    vector<int> b;
    int cur = 0, rem = 0;
    for(int x = n; x >= 0; --x){
        for(int i = 0; i < (mn[x] - cur); ++i){
            b.push_back(x + 1);
        }
        cur = mn[x];
        rem += freq[x] - mn[x];
    }
    for(int i = 0; i < rem; ++i){
        b.push_back(0);
    }
    cout << b.size() << '\n';
    for(int elem : b){
        cout << elem << ' ';
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
