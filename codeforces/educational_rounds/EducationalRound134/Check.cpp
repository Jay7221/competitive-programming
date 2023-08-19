#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("output.out", "r", stdin);
    string t;
    cin >> t;
    cerr << t << '\n';
    vector<string> v;
    while(cin >> t)
        v.push_back(t);
    freopen("expected.out", "r", stdin);
    int ind = 0;
    while(cin >> t){
        cerr << t << '\n';
        if(t == v[ind])
            ++ind;
        else{
            cerr << ind << '\n';
            cerr << v[ind] << ' ' << t << '\n';
            break ;
        }
    }
}