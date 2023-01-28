#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int posa[2][n];
        memset(posa,0,sizeof posa);
        for(int i = 0;i < n;i++){
            cin>>arr[i];
            posa[i % 2][arr[i] - 1]++;
        }
        map<ii,int>cur,res;
        ii last = {-1,-1};
        for(int i = 1;i < n;i++){
            ii tora = {arr[i],arr[i-1]};
            if(i % 2){
                swap(tora.first,tora.second);
            }
            if(tora != last){
                res[last] += cur[last] / 2; 
                cur[last] = 0;
                last = tora;
                cur[last] = 2;
            }
            else{
                cur[last]++;
            }
        }
        res[last] += cur[last] / 2; 
        cur[last] = 0;
        int ans = 10 * n;
        set<ii>ex;
        vector<int>ad[n];
        for(int i = 0;i < n;i++){
            ad[i].push_back(i);
        }
        for(auto x:res){
            if(x.first.first >= 0){
                ans = min(ans,n - posa[1][x.first.first - 1] - posa[0][x.first.second - 1] + x.second);
                ad[x.first.second-1].push_back(x.first.first-1);
            }
        }
        for(int i = 0;i < n;i++){
            ex.insert({posa[1][i],i});
        }
        for(int i = 0;i < n;i++){
            for(auto x:ad[i]){
                ex.erase({posa[1][x],x});
            }
            if(!ex.empty()){
                auto it = ex.rbegin();
                ans = min(ans,n - posa[0][i] - (*it).first);
            }
            for(auto x:ad[i]){
                ex.insert({posa[1][x],x});
            }
        }
        cout<<ans<<"\n";
    }
}