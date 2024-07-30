#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    vector<int> v;
    while(true){
        cin >> num;
        if(num < 0){
            break;
        }
        v.push_back(num);
    }
    int ans = 0;
    for(int i = 0; i < v.size(); ++i){
        ans += (v[i] % 6 == 0);
    }
    cout << ans << '\n';
}
