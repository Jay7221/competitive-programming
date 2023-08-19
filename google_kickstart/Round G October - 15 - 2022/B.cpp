#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	ll Rs, Rh;
	cin >> Rs >> Rh;
	auto check = [&](ll d){
		if(d > ((Rs + Rh) * (Rs + Rh)))
			return false;
		else
			return true;
	};
	vector<ll> red, yellow;
	ll red_score = 0, yellow_score = 0;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; ++i){
		ll x, y;
		cin >> x >> y;
		ll d = x * x + y * y;
		if(check(d))
			red.push_back(d);
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		ll x, y;
		cin >> x >> y;
		ll d = x * x + y * y;
		if(check(d))
			yellow.push_back(d);
	}
	ll y_min = INF, r_min = INF;
	for(auto elem : yellow)
		y_min = min(y_min, elem);
	for(auto elem : red)
		r_min = min(r_min, elem);

	for(auto elem : red){
		if(elem < y_min)
			++red_score;
	}
	for(auto elem : yellow){
		if(elem < r_min){
			++yellow_score;
		}
	}
	cout << red_score << ' ' << yellow_score << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}