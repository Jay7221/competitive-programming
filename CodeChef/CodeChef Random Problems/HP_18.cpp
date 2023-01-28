#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod (ll)(1e9 + 7)
void solve(){
    int n, a, b;
    cin >> n >> b >> a;
    int num[n];
    int alice = 0, bob = 0, alice_and_bob = 0;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if((num[i] % a == 0) && (num[i] % b == 0)){
            alice_and_bob++;
        }
        else if(num[i] % a == 0){
            alice++;
        }
        else if(num[i] % b == 0){
            bob++;
        }
    }
    if(alice_and_bob > 0){
        if(alice > bob){
            cout << "ALICE\n";
        }
        else{
            cout << "BOB\n";
        }
    }else{
        if(bob > alice){
            cout << "BOB\n";
        }
        else{
            cout << "ALICE\n";
        }
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
     solve();
    }
}