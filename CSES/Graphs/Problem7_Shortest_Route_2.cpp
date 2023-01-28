#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (ll)(1e15 + 10)
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll> > dist(n, vector<ll>(n, inf));
	for(int i = 0; i < n; i++)
		dist[i][i] = 0;
	for(int i = 0; i < m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = dist[a][b];
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j= 0; j < n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(dist[a][b] == inf){
			cout << -1 << '\n';
		}else{
			cout << dist[a][b] << '\n';
		}
	}
}