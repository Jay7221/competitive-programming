#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
#define ll long long
int main() {
	// Your code here
    ll a[3];
    for(int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }
    bool flag = false;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = i + 1; j < 3; ++j)
        {
            ll sum = a[i] + a[j];
            if((sum % 2 == 0) && (sum > 0))
            {
                flag = true;
            }
        }
    }
    if(flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
