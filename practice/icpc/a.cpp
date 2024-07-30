#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> s(3);
    for(int i = 0; i < 3; ++i){
        cin >> s[i];
    }
    string res = "CCC";
    function<void(int, int, string)> dfs;
    dfs = [&](int i, int j, string cur){
        if((i < 0) || (j < 0) || (i > 2) || (j > 2)){
            return;
        }
        cur.push_back(s[i][j]);
        char prev = s[i][j];
        s[i][j] = 'Z';
        if(cur.size() == 3){
            res = min(res, cur);
        }
        else{
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    if((dx == 0) && (dy == 0)){
                        continue;
                    }
                    int x = i + dx, y = j + dy;
                    dfs(x, y, cur);
                }
            }
        }
        s[i][j] = prev;
        cur.pop_back();
    };
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            string cur;
            dfs(i, j, cur);
        }
    }
    cout << res << '\n';
}
