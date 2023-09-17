#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;

    string ans;

    char cur = str[0];
    int cnt = 0;

    for(char ch : str){
        if(ch == cur){
            ++cnt;
        }
        else{
            ans.push_back(cur);
            ans += to_string(cnt);
            cnt = 1;

            cur = ch;
        }
    }

    ans.push_back(cur);
    ans += to_string(cnt);
    cnt = 0;


    cout << ans << '\n';
    
    return 0;
}
 
