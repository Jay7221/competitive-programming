#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n;
	cin >> x >> n;
	unordered_map<int, int> size;
	// size[i] = max length of unlit passage ending at i
	set<pair<int, int>, greater<pair<int, int> > > s;
	// s -> {d, p} = {max size of passage ending at p, position p}
	set<int> pos;
	// pos stores the positions at which the street lights are lit
	size[x] = x;
	pos.insert(x);
	s.insert({x, x});
	vector<int> a(n);
	for(int i = 0; i < n ;i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		int p = a[i];
		auto k = pos.upper_bound(p);
		int pp = *k;
		pos.insert(p);
		s.erase({size[pp], pp});
		size[p] = size[pp] - (pp - p);
		size[pp] -= size[p];
		s.insert({size[p], p});
		s.insert({size[pp], pp});
		cout << s.begin() -> first << ' ' ;
	}
}