#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll maxsum = 0;
    int minmoves = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxsum += abs(a[i]);
        if(a[i] < 0){
            if(!flag){
                flag = true;
                ++minmoves;
            }
        }
        if(a[i] > 0){
            flag = false;
        }
    }
    cout << maxsum << ' ' << minmoves << '\n';
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
