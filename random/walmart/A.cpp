#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool possible(vector<int> arr, int target){
    bitset<MAX> dp;
    dp[0] = true;
    for(int elem: arr){
        dp |= (dp << elem);
    }
    return dp[target];
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int MASK = (1 << n);
    int ans = 0;
    for(int mask = 0; mask < MASK; ++mask){
        vector<int> v;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            if(1 & (mask >> i)){
                cur += a[i];
            }
            else{
                v.push_back(a[i]);
            }
        }
        if(possible(v, cur)){
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}
