#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    bool flag = false;
    vector<int> v;

    if(x == 1){
        if(k > 1){
            if(n & 1){
                // n is odd
                if(k > 2){
                    flag = true;
                    v.push_back(3);
                    n -= 3;
                    for(int i = 0; i < (n / 2); ++i){
                        v.push_back(2);
                    }
                }
            }else{
                // n is even
                flag = true;
                for(int i = 0; i < (n / 2); ++i){
                    v.push_back(2);
                }
            }
        }
    }else{
        flag = true;
        for(int i = 0; i < n; ++i){
            v.push_back(1);
        }
    }

    
    if(flag){
        cout << "YES\n";
        cout << v.size() << '\n';
        for(int elem : v){
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
