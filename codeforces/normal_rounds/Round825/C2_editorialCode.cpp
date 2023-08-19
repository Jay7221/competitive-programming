#include <bits/stdc++.h>     
using namespace std;
#define ll long long
#define f first
#define s second
int main()                                                                                
{  
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);  
    ll n; cin>>n;
    vector<ll> dp(n+5,0),sum(n+5,0);
    vector<pair<ll,pair<ll,ll>>> track; 
    vector<ll> pref(n+5,0),len(n+5,0);
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        sum[i]=sum[i-1]+i; track.push_back({x-i,{i,0}});
        len[i]=min(len[i-1]+1,x); pref[i]=pref[i-1]+len[i];    
    }
    ll q; cin>>q;
    vector<ll> ans(q+5,0);  
    for(ll i=1;i<=q;i++){
        ll p,x; cin>>p>>x; x=min(len[p-1]+1,x); 
        track.push_back({x-p,{p,i}});
    }
    set<ll> found; found.insert(n+1);  
    sort(track.begin(),track.end()); 
    for(auto it:track){
        if(it.s.s){
            ll r=*found.upper_bound(it.s.f);
            ans[it.s.s]=pref[it.s.f-1]+dp[r]+sum[r-it.s.f]+(it.f+it.s.f-1)*(r-it.s.f);
        }
        else{
            ll r=*found.lower_bound(it.s.f); found.insert(it.s.f);
            dp[it.s.f]=dp[r]+sum[r-it.s.f]+(it.f+it.s.f-1)*(r-it.s.f);
        }
    }
    for(ll i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
} 