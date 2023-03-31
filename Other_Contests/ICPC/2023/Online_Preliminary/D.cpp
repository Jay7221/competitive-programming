#include<bits/stdc++.h>
using namespace std;
#define ll long long
double dist(double a, double b, double c, double d){
	double dist = (a - c) * (a - c) + (b - d) * (b - d);
	dist = sqrt(dist);
	return dist;
}
void solve(){
	int ux, uy, dx, dy;
	cin >> ux >> uy >> dx >> dy;
	int cx, cy, n;
	cin >> cx >> cy >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; ++i){
		int x, y;
		double r;
		cin >> x >> y >> r;
		double d = dist(x, y, cx, cy);
		double low = d - r, high = d + r;
		int dl = ceil(low), dr = floor(high);
		if(low == dl){
			++dl;
		}
		if(high == dr){
			--dr;
		}
		if(dl <= dr){
			v.push_back({dl, dr});
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int mx_r = min({abs(cx - ux), abs(cx - dx), abs(cy - uy), abs(cy - dy)});
	vector<int> no_r(mx_r + 7);
	for(auto [l, r] : v){
		l = min(l, mx_r + 1);
		r = min(r, mx_r + 1);
		++no_r[l];
		--no_r[r + 1];
	}
	for(int i = 1; i <= mx_r; ++i){
		no_r[i] += no_r[i - 1];
	}
	for(int i = 1; i <= mx_r; ++i){
		if(no_r[i] == 0){
			++ans;
		}
	}
	cout << ans << '\n';

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case " << i << ": ";
		solve();
	}

	return 0;
}
