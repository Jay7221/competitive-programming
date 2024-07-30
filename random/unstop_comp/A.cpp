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
int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> v = getZ(t + "$" + s);
    int cnt = 0;
    for(int i = m + 1; i < n + m + 1; ++i){
        if(v[i] == m){
            ++cnt;
            i += m - 1;
        }
    }
    if(cnt & 1){
        cout << "Alice";
    }
    else{
        cout << "Bob";
    }
}
