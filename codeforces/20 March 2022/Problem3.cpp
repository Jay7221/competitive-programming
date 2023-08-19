#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define debug(a, n) for(int i = 0; i < n; i++){cerr << a[i] << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	priority_queue<ll> cake, pieces;
	ll a, sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a;
		pieces.push(a);
		sum += a;
	}
	cake.push(sum);
	ll p, q;
	while(!cake.empty() && !pieces.empty()){
		p = cake.top();
		q = pieces.top();
		if(p < q)
			break;
		if(p == q){
			cake.pop();
			pieces.pop();
		}
		if(p > q){
			cake.pop();
			cake.push(p/2);
			cake.push((p + 1)/2);
		}
	}
	if(cake.empty() && pieces.empty()){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}