#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	ll n, x;
	cin >> n >> x;
	queue<ll> q;
	q.push(x);
	map<ll, ll> dist;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		string s = to_string(u);
		if(s.size() == n){
			cout << dist[u] ;
			return ;
		}
		for(auto i : s){
			i -= '0';
			if(i < 2)
				continue ;
			if(!dist[u * i]){
				dist[u * i] = dist[u] + 1;
				q.push(u * i);
			}
		}
	}
	cout << -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}