#include<bits/stdc++.h>
using namespace std;
bool check(string pat, string text, int i, int j){
    if((i == (int)pat.size()) && (j == (int)text.size())){
        return true;
    }
    if((i == (int)pat.size()) || (j == (int)text.size())){
        return false;
    }
    if(pat[i] == text[j]){
        return check(pat, text, i + 1, j + 1);
    }
    if(pat[i] == '*'){
        for(int r = j; r <= (int)text.size(); ++r){
            if(check(pat, text, i + 1, r)){
                return true;
            }
        }
    }
    return false;
}
void solve(){
    string p, t;
    cin >> p >> t;
    if(check(p, t, 0, 0)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    solve();
}
