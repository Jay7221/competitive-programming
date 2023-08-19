#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int alice = 0, bob = 0;
    char server = 'A';
    for(char winner : s){
        if(winner == 'A'){
            if(server == 'A'){
                ++alice;
            }else{
                server = 'A';
            }
        }else{
            if(server == 'B'){
                ++bob;
            }else{
                server = 'B';
            }
        }
    }
    cout << alice << ' ' << bob << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
