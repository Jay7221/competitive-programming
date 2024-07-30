#include<bits/stdc++.h>
using namespace std;
int leastMoves(int n, int a[]){
    vector<bool> vis(n);
    vector<bool> dVis(10);
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int d, i;
        tie(d, i) = q.front();
        if(vis[i]){
            continue;
        }
        q.pop();
        vis[i] = true;
        if(i == n - 1){
            return d;
        }
        if(!dVis[a[i]]){
            for(int j = 0; j < n; ++j){
                if(!vis[j] && (a[j] == a[i])){
                    q.push({d + 1, j});
                }
            }
            dVis[a[i]] = true;
        }
        if((i - 1 >= 0) && !vis[i - 1]){
            q.push({d + 1, i - 1});
        }
        if((i + 1 < n) && !vis[i + 1]){
            q.push({d + 1, i + 1});
        }
    }
    return n;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << leastMoves(n, a) << '\n';
    return 0;
}
