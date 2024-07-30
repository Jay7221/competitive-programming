#include<bits/stdc++.h>
using namespace std;
char* SbString(char* input1){
    int n = strlen(input1);
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        int l = i, r = i;
        while((l - 1 >= 0) && (r + 1 < n) && (input1[l - 1] == input1[r + 1])){
            --l;
            ++r;
        }
        if(r - l > y - x){
            x = l;
            y = r;
        }
    }
    for(int i = 1; i < n; ++i){
        int l = i, r = i - 1;
        while((l - 1 >= 0) && (r + 1 < n) && (input1[l - 1] == input1[r + 1])){
            --l;
            ++r;
        }
        if(r - l > y - x){
            x = l;
            y = r;
        }
    }
    string res;
    for(int i = x; i <= y; ++i){
        res.push_back(input1[i]);
    }
    return (char*)res.c_str();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string res(SbString((char*)s.c_str()));
        cout << res << '\n';
    }
    return 0;
}
