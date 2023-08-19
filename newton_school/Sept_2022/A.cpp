#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	// Your code here
    int a, b;
    cin >> a >> b;
    if(pow(a, b) > pow(b, a)){
        cout << "First";
    }else if(pow(a, b) < pow(b, a)){
        cout << "Second";
    }else{
        cout << "Equal";
    }
    return 0;
}