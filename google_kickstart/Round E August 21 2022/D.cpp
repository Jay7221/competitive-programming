#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(int t){
	int n, p, m, ax, ay;
	cin >> n >> p >> m >> ax >> ay;
	--ax, --ay;
	vector<char> OP(5);
	vector<ll> Kd(5);
	OP[0] = '+', Kd[0] = 0;
	for(int i = 1; i < 5; ++i)
		cin >> OP[i] >> Kd[i];
	vector<vector<int> > is_cus(n, vector<int>(n, -1));
	vector<vector<ll> > coin(n, vector<ll>(n));
	for(int i = 0; i < p; ++i){
		ll x, y, c;
		cin >> x >> y >> c;
		--x, --y;
		is_cus[x][y] = i;
		coin[x][y] = c;
	}
	vector<tuple<ll, ll, ll> > d = {{0, 0, 0}, {-1, 0, 1}, {0, 1, 2}, {0, -1, 3}, {1, 0, 4}};
	ll max_mask = (1 << p);
	ll dp[n][n][max_mask][m + 1];
	for(int i = 0; i < n ;++i){
		for(int j = 0; j< n; ++j){
			for(int mask = 0; mask < max_mask; ++mask){
				for(int t = 0; t <= m; ++t){
					dp[i][j][mask][t] = -INF;
				}
			}
		}
	}

	auto operate = [&](ll cur, ll ind){
		switch(OP[ind]){
			case '+':
				return cur + Kd[ind];
				break ;
			case '-':
				return cur - Kd[ind];
				break ;
			case '*':
				return cur * Kd[ind];
				break ;
			case '/':
				return (ll)floor((double)cur / (double)Kd[ind]);
				break ;
		}
	};
	auto check = [&](ll a, ll b){
		if(a < 0 || b < 0 || a > n - 1 || b > n - 1)
			return 0;
		return 1;
	};

	dp[ax][ay][0][0] = 0;
	for(int t = 0; t < m; ++t){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				for(int mask = 0; mask < max_mask; ++mask){
					if(dp[i][j][mask][t] == -INF)
						continue ;
					for(auto p : d){
						ll dx, dy, ind;
						tie(dx, dy, ind) = p;
						int x = i + dx, y = j + dy;
						if(!check(x, y))
							continue;
						dp[x][y][mask][t + 1] = max(dp[x][y][mask][t + 1], 
							operate(dp[i][j][mask][t], ind));
					}
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(is_cus[i][j] == -1){
					continue ;
				}
				int cus = (1 << is_cus[i][j]);
				for(int mask = 0; mask < max_mask; ++mask){
					if(!(mask & cus))
						continue ;
					ll cur = dp[i][j][mask ^ cus][t + 1];
					if(cur == -INF)
						continue;
					dp[i][j][mask][t + 1] = max(dp[i][j][mask][t + 1], dp[i][j][mask ^ cus][t + 1] + coin[i][j]);
				}
			}
		}
	}
	ll ans = -INF;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			ans = max(ans, dp[i][j][max_mask - 1][m]);
		}
	}
	//--------------- OUTPUT ------------------------------
	cout << "Case #" << t << ": ";
	if(ans == -INF)
		cout << "IMPOSSIBLE\n";
	else{
		cout << ans << '\n';
	}
	// -------------- End of OUTPUT -----------------------
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}