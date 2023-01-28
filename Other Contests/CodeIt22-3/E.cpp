#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int p, q;
        cin >> p >> q;
        cout << (p + q) << '\n';
    }
    return 0;
}