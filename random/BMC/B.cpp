#include<bits/stdc++.h>
using namespace std;
void processArray(vector<int> &arr){
    int sz = 0;
    int n = arr.size();
    for(int i = 0; i < n; ++i){
        if(arr[i] < 100){
            int sum = 0;
            while(true){
                sum += arr[i];
                if((i + 1 < n) && (arr[i + 1] < 100)){
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
    arr.resize(sz);
}
int processArray(int arr[], int n){
    int sz = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] < 100){
            int sum = 0;
            while(true){
                sum += arr[i];
                if((i + 1 < n) && (arr[i + 1] < 100)){
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
