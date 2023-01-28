#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define print(a) cerr << a.first << ' ' << a.second << '\n';
class DSU{
public:
	map<pair<int, int>, pair<int, int> > par;
	map<pair<int, int>, int> size;
	DSU(vector<pair<int, int> >& red, vector<pair<int, int> >& blue){
		for(auto c : red){
			par[c] = c;
			size[c] = 1;
		}
		for(auto c : blue){
			par[c] = c;
			size[c] = 1;
		}
	}
	pair<int, int> find(pair<int, int> tar){
		if(par[tar] == tar)
			return tar;
		return par[tar] = find(par[tar]);
	}
	void merge(pair<int, int> u, pair<int, int> v){
		u = find(u), v = find(v);
		if(size[u] < size[v])
			swap(u, v);
		par[v] = u;
		size[u] += size[v];
	}
};
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int> > red, blue;
	while(n--){
		int c, l, r;
		cin >> c >> l >> r;
		if(c == 0)
			red.push_back({l, r});
		else
			blue.push_back({l, r});
	}
	DSU data(red, blue);
	for(auto seg : red){
		int l, r;
		tie(l, r) = seg;
		auto seg_d = lower_bound(blue.begin(), blue.end(), seg);
		if(seg_d == blue.end())
			continue ;
		int a, b;
		tie(a, b) = *seg_d;
		if(a <= l && l <= b)
			data.merge(seg, *seg_d);
		else if(a <= r && r <= b)
			data.merge(seg, *seg_d);
		else if(l <= a && a <= r)
			data.merge(seg, *seg_d);
		else if(l <= b && b <= r)
			data.merge(seg, *seg_d);
	}
	for(auto seg : blue){
		int l, r;
		tie(l, r) = seg;
		auto seg_d = lower_bound(red.begin(), red.end(), seg);
		if(seg_d == red.end())
			continue ;
		int a, b;
		tie(a, b) = *seg_d;
		if(a <= l && l <= b)
			data.merge(seg, *seg_d);
		else if(a <= r && r <= b)
			data.merge(seg, *seg_d);
		else if(l <= a && a <= r)
			data.merge(seg, *seg_d);
		else if(l <= b && b <= r)
			data.merge(seg, *seg_d);
	}
	map<pair<int, int>, int> freq;
	for(auto c : red)
		++freq[data.find(c)];
	for(auto c : blue)
		++freq[data.find(c)];
	cout << freq.size() << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}