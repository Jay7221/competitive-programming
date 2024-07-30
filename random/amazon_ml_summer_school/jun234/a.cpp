#include<bits/stdc++.h>
using namespace std;

int findPairs(int input1, int input2[]){
    int n = input1;
    int* arr = input2;

    int mx = *max_element(arr, arr + n);
    int dp[mx + 1];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= mx; ++i){
        for(int j = i + 1; i * j <= mx; ++j){
            dp[i * j] += 2;
        }
    }
    for(int i = 1; i * i <= mx; ++i){
        ++dp[i * i];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += dp[arr[i]];
    }

    return ans;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << findPairs(n, a) << '\n';
    return 0;
}
