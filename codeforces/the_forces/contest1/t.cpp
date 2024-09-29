#include<bits/stdc++.h>

using namespace std;
int main(){
    string query = "Enter a string: ";
    while(true){
        cout << query;
        string s;
        cin >> s;
        cout << "\e[A";
        for(int i = 0; i < (int)(query.size() + s.size()); ++i){
            cout << "\b";
        }

    }
}
