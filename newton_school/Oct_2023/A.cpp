#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
    int a, b, x, y, k;
    cin >> a >> b >> x >> y >> k;
    int val = a * x + b * y;
    if(val >= k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
