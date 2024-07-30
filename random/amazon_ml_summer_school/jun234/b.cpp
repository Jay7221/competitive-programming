#include<bits/stdc++.h>
using namespace std;
struct Result{
    Result(): output1(){};
    int output1[10000];
};
Result compute(int input1, int input2[]){
    int n = input1;
    int *arr = input2;

    Result res;

    for(int i = 0; i < n; ++i){
        res.output1[i] = -max(arr[i] - arr[0], arr[n - 1] - arr[i]);
    }

    long long cur = 0;
    for(int i = 0; i < n; ++i){
        res.output1[i] += i * arr[i] - cur;
        cur += arr[i];
    }
    cur = 0;
    for(int i = n - 1; i >= 0; --i){
        res.output1[i] += cur - (n - 1 - i) * arr[i];
        cur += arr[i];
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    Result res = compute(n, a);
    for(int i = 0; i < n; ++i){
        cout << res.output1[i] << ' ';
    }
    cout << '\n';
    return 0;
}
