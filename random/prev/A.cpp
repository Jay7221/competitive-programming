#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, s;
    cin >> a;

    int n = a.size();
    auto check = [](char ch){
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(char c : v){
            if(c == ch){
                return false;
            }
        }
        return true;
    };
    auto check1 = [&](int i){
        if(check(a[i])){
            return true;
        }
        if((i > 0) && !check(a[i - 1])){
            return true;
        }
        if((i < n - 1) && !check(a[i + 1])){
            return true;
        }
        return false;
    };

    for(int i = 0; i < n; ++i){
        if(check1(i)){
            s.push_back(a[i]);
        }
    }
    cout << s << '\n';
    return 0;
}
