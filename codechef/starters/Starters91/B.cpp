#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << -1 << '\n';
        return;
    }

    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }
    reverse(p.begin(), p.end());
    for(int elem : p){
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
