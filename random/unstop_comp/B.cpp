#include<bits/stdc++.h>
using namespace std;
vector<int> getZ(string s){
    int n = s.size();
    vector<int> z(n);
    int l = 1;
    for(int i = 1; i < n; ++i){
        z[i] = z[i - l];
        while((i + z[i] < n) && (s[i + z[i]] == s[z[i]])){
            ++z[i];
        }
        if((i + z[i]) >= (l + z[l])){
            l = i;
        }
    }
    return z;
}
bool check(string s, string t){
    vector<int> v = getZ(t + "$" + s);
    int m = t.size();
    for(int elem: v){
        if(elem == m){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> st;
    for(int i = 0; i < n; ++i){
        string tmp;
        for(int j = i; j < n; ++j){
            tmp += s[j];
            st.insert(tmp);
        }
    }
}
