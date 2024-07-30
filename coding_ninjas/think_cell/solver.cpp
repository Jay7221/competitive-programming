#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 7;

int main(){
    int q, beg;
    cin >> q >> beg;
    vector<int> arr(MAX, beg);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k1, k2, v;
            cin >> k1 >> k2 >> v;
            for(int i = k1; i < k2; ++i){
                arr[i] = v;
            }
        }
        else{
            int k;
            cin >> k;
            cout << arr[k] << '\n';
        }
    }
    return 0;
}
