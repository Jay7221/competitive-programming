#include <bits/stdc++.h>
 
using namespace std;
 
 
int getArea(int a, int b, int c){
    return max(0, ( ( a + b + c ) * ( a + b - c ) * ( a - b + c ) * ( -a + b + c) ));
}
int main() {
    
    cerr << "Hello Linux from checker!" << endl;
    vector<int> a = {1, 1, 1, 2, 2, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = a.size();
    cout << n << endl;
    char ch;
    cin >> ch;
    while(ch != '!'){
        int i, j, k;
        cin >> i >> j >> k;
        --i, --j, --k;
        cout << getArea(a[i], a[j], a[k]) << endl;
        cin >> ch;
    }
    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
 
