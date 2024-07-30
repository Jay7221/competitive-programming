#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll P=1e9+7;
ll calc(ll r,ll a){
	ll ans=0,t=a;
	while(t<=r){
		ans+=(r-t+1)%P;
		ans%=P;
		if(t<=r/a)t=t*a;
		else break;
	}
	return ans;
}
ll solve(ll x){
	ll res=0;
	for(ll i=2;i<=62;++i){
		ll l=1ll<<i,r=(1ll<<(i+1))-1;
		if(l>x)break;
		r=min(r,x);
		res+=calc(r,i)-calc(l-1,i)+P;
		res%=P;
	}
	return res;
}
int main(){
	//freopen("hayasa","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(P+solve(r)-solve(l-1))%P);
	}
}

