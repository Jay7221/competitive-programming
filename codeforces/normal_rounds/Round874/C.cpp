#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    bool flag = true;
    sort(a.begin(), a.end());
    if(a[0] % 2 == 0){
        for(int i = 0; i < n; ++i){
            if(a[i] % 2 == 1){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
