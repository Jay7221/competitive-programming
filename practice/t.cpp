#include<bits/stdc++.h>
using namespace std;
int main(){
    const int MAX = 3e5 + 7;
    vector<int> pre(MAX);
    for(int i = 1; i < MAX; ++i){
        pre[i] = pre[i - 1] ^ i;
    }
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(pre[a - 1] == b){
            cout << a << '\n';
        }
        else if((pre[a - 1] ^ b) == a){
            cout << a + 2 << '\n';
        }
        else{
            cout << a + 1 << '\n';
        }
    }
    return 0;
}
