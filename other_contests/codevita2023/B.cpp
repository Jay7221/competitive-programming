#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll get(string s){
    map<string, ll> mp;
    vector<string> extend = {"", "L", "M", "LM", "ML"};
    mp[""] = 1;
    for(char ch : s){
        for(string ex : extend){
            string cur = ex;
            cur.push_back(ch);
            mp[cur] += mp[ex];
        }
    }
    return (mp["LML"] + mp["MLM"]);
}
bool check(string s){
    return ((int)s.size() == (count(s.begin(), s.end(), 'M') + count(s.begin(), s.end(), 'L')));
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    string a, b;
    cin >> a >> b;
    if(!(check(a) && (check(b)))){
        cout << "Invalid input";
        return 0;
    }
    ll na = get(a), nb = get(b);
    if(na > nb){
        cout << "Ashok";
    }
    else if(na < nb){
        cout << "Anand";
    }
    else{
        cout << "Draw";
    }
    
    return 0;
}
 
