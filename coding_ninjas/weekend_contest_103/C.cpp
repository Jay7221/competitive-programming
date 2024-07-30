#include<bits/stdc++.h>
using namespace std;
string findLexicographicalMinimum(int n, string s) {
    vector<vector<int>> prev(26);
    for(int i = 0; i < n; ++i){
        int c = s[i] - 'a';

        int p = -1;
        while(prev[c].size() > 0){
            int pp = prev[c].back();
            if(s[pp] == s[i]){
                p = pp;
                break;
            }
            else{
                prev[c].pop_back();
            }
        }
        if(p > -1){
            bool update = false;
            for(int j = p + 1; j < i; ++j){
                if(s[j] > s[i]){
                    update = true;
                    break;
                }
                else if(s[j] < s[i]){
                    break;
                }
            }
            if(update){
                cerr << s[i] << ' ' << i << ' ' << p << '\n';
                cerr << s << '\n';
                for(int j = p; j < i; ++j){
                    s[j] = s[i];
                }
                cerr << s << '\n';
            }
        }
        prev[c].push_back(i);
    }
    return s;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << findLexicographicalMinimum(n, s) << '\n';
    }
}
