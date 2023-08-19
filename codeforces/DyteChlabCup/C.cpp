#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > coords;
	vector<int> l(3), r(3);
	for(int i = 0; i < 3; ++i){
		cin >> l[i] >> r[i];
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int xx = l[1], yy = r[1];
	int x, y;
	cin >> x >> y;

	bool flag = true;
	if((xx == 1) && (yy == 1)){
		flag = false;
		if(x == 3 && y == 1)
			flag = true;
		if(x == 1 && y == 3)
			flag = true;
	}
	else if((xx == 1) && (yy == n)){
		flag = false;
		if(x == 3 && y == n)
			flag = true;
		if(x == 1 && y == n - 2)
			flag = true;
	}
	else if((xx == n) && (yy == 1)){
		flag = false;
		if(x == n - 2 && y == 1)
			flag = true;
		if(x == n && y == 3)
			flag = true;
	}
	else if((xx == n) && (yy == n)){
		flag = false;
		if(x == n - 2 && y == n)
			flag = true;
		if(x == n && y == n - 2)
			flag = true;
	}
	else{
		int dx = abs(xx - x), dy = abs(yy - y);
		if((dx % 2 == 1) && (dy % 2 == 1))
			flag = false;
	}
	cerr << x << ' '<< y << "\n";
	cerr << xx << ' ' << yy << '\n';
	cerr << "\n\n";
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}