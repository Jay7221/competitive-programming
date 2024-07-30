#include<bits/stdc++.h>
using namespace std;
int processArray(int arr[], int n){
    int sz = 0;
    auto check = [](int x){
        return ((99 < x) && (x < 1000));
    };
    for(int i = 0; i < n; ++i){
        if(check(arr[i])){
            int sum = 0;
            while(true){
                sum += arr[i];
                if((i + 1 < n) && (check(arr[i + 1]))){
                    ++i;
                }
                else{
                    break;
                }
            }
            arr[sz] = sum;
            ++sz;
        }
        else{
            arr[sz] = arr[i];
            ++sz;
        }
    }
    return sz;
}
int main(){
    int arr[100000];
    int n = 0;
    int num;
    while(true){
        cin >> num;
        if(num == -1){
            break;
        }
        arr[n] = num;
        ++n;
    }
    n = processArray(arr, n);
    for(int i = 0; i < n; ++i){
        cout << arr[i] << '\n';
    }
}
