#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }

    int i1, i2, in;
    for(int i = 0; i < n; ++i){
        if(p[i] == 1){
            i1 = i + 1;
        }
        if(p[i] == 2){
            i2 = i + 1;
        }
        if(p[i] == n){
            in = i + 1;
        }
    }

    int a = i1, b = i1;

    if(in < min(i1, i2)){
        a = in, b = min(i1, i2);
    }
    if(in > max(i1, i2)){
        a = in, b = max(i1, i2);
    }


    cout << a << ' ' << b << '\n';
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
