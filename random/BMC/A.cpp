#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    vector<int> a;
    while(true){
        cin >> num;
        if(num == -1){
            break;
        }
        a.push_back(num);
    }
    int ans = 0;
    for(int elem : a){
        if((elem < 100) && (ans < elem)){
            ans = elem;
        }
    }
    cout << ans << '\n';
}
