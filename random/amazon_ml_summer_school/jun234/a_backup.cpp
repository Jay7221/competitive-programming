#include<bits/stdc++.h>
using namespace std;
int findPairs(int input1, int input2[]){
    int n = input1;
    int* arr = input2;

    for(int i = 0; i < n; ++i){
    }
    map<int, bool> mp;

    for(int i = 0; i < n; ++i){
        mp[arr[i]] = true;
    }
    int mx = *max_element(arr, arr + n);
    int ans = 0;
    for(int i = 1; i <= mx; ++i){
        for(int j = i; j <= mx; ++j){
            if(mp[i * j]){
                ans += 1 + (i != j);
            }
        }
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
