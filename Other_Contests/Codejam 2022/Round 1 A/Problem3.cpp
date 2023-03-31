#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (ll)(1e14 + 5)
void solve(){
	int e, w;
	cin >> e >> w;
	vector<vector<int> > x(e, vector<int>(w, 0));
	for(int i = 0; i < e; i++){
		for(int j = 0; j < w; j++)
			cin >> x[i][j];
	}
	vector<vector<ll> > c(e, vector<ll>(e, 0));
	vector<vector<ll> > m(e, vector<ll>(e, 0));
	for(int i = 0; i < w; i++){
		for(int p = 0; p < e; p++){
			int mn = x[p][i];
			for(int q = p; q < e; q++){
				mn = min(mn, x[q][i]);
				c[p][q] += mn;
			}
		}
	}
	for(int r = 1; r < e; r++){
		for(int l = r - 1; l > -1; l--){
			m[l][r] = mx;
			for(int x = l; x < r; x++){
				m[l][r] = min(m[l][r], m[l][x] + m[x + 1][r] + 2 * (c[l][x] + c[x + 1][r] - 2 * c[l][r]));
			}
		}
	}
	cout << (m[0][e - 1] + 2 * c[0][e - 1]) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}