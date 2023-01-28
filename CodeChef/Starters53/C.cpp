#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	set<pair<int, int> > s;
	for(int i = 0; i < n; ++i)
		s.insert({a[i] + b[i], i});
	int fir = 0, sec= 0;
	bool flag = 1;
	while(s.size()){
		int ind, tmp;
		tie(tmp, ind) = *(--s.end());
		s.erase(--s.end());
		if(flag)
			fir += a[ind];
		else
			sec += b[ind];
		flag ^= 1;
	}
	if(fir > sec)
		cout << "First\n";
	else if(sec > fir)
		cout << "Second\n";
	else
		cout << "Tie\n";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}