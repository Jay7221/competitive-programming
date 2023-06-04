#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')){
        cout << -1 << '\n';
        return;
    }
    vector<int> v(n);

    int color = 0;
    int cur = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            ++cur;
        }else{
            --cur;
        }
        if(color){
            if(cur < 0){
                color ^= 1;
            }
        }else{
            if(cur > 0){
                color ^= 1;
            }
        }
        v[i] = color;
    }
    int k = 1;
    if(count(v.begin(), v.end(), 0) != n && count(v.begin(), v.end(), 1) != n){
        k = 2;
    }
    if(k == 1){
        for(int &elem : v){
            elem = 0;
        }
    }
    cout << k << '\n';
    for(int elem : v){
        ++elem;
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
