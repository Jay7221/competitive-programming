#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n, 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int last = a[0];
    bool flag = false;
    for(int i = 1; i < n; ++i){
        if(flag){
            if((a[i] > a[0]) || (a[i] < last)){
                b[i] = 0;
            }else{
                last = a[i];
            }
        }else{
            if(a[i] < last){
                if(a[i] <= a[0]){
                    last = a[i];
                    flag = true;
                }else{
                    b[i] = 0;
                }
            }
            else{
                last = a[i];
            }
        }
    }
    for(int elem : b){
        cout << elem;
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
