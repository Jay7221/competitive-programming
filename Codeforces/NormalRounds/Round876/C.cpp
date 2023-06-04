#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    bool flag = true;
    int rem = n;
    vector<int> p;
    for(int i = 1; i <= n; ++i){
        if(rem > n - i){
            p.push_back(i - 1);
            --rem;
        }
        if(a[i] == 1){
            if(rem % 2 == 0){
                if(rem == 0){
                    flag = false;
                    break;
                }
                --rem;
                p.push_back(i - 1);
            }
        }else{
            if(rem % 2 == 1){
                --rem;
                p.push_back(i - 1);
            }
        }
    }
    if(flag){
        cout << "YES\n";
        for(int elem : p){
            cout << elem << ' ';
        }
        cout << '\n';
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
