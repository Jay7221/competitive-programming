#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool> vis(n + 1);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(vis[a]){
            cout << a << ' ';
        }else{
            vis[a] = true;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            cout << i << '\n';
        }
    }
    return 0;
}