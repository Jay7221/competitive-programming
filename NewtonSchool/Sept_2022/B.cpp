#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

void solve(){
    vector<int> a(3);
    for(int i = 0; i < 3; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k = a[0] + a[1] - a[2];
    if((k < 0) || (k % 2)){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
}
int main() {

	// Your code here
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}