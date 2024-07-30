#include<bits/stdc++.h>
using namespace std;
int getRand(int mn, int mx){
    int diff = mx - mn + 1;
    return (mn + rand() % diff);
}
int main(){
    srand(time(0));
    int n = 10;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = i + 1;
    }
    random_shuffle(arr.begin(), arr.end());
    int alpha = 10;
    for(int i = 2; i <= n; ++i){
        int p = getRand(max(1, i - alpha), i - 1);
        int u = arr[p - 1];
        int v = arr[i - 1];
        cout << u << ' ' << v << '\n';
    }
}
