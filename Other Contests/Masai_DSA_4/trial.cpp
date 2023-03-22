#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void print(multiset<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
vector<int> solve(int n, vector<int> level) {
	++n;
	vector<int> freq(n), nodeFreq(n), d(n), subtree(n), mxDist(n), deg(n);
	int num_subtree = 0;
	vector<int> ans;
	freq[0] = 1;
	nodeFreq[0] = 1;
	multiset<int> m;
	m.insert(0);
	int mx = 0, prev = 0;
	for(int i = 1; i < n; ++i){
		int u = level[i - 1] - 1;
		d[i] = d[u] + 1;
		if(u == 0){
			subtree[i] = num_subtree;
			++num_subtree;
			mxDist[subtree[i]] = d[i];
			++freq[mxDist[subtree[i]]];
			m.insert(mxDist[subtree[i]]);
		}else{
			subtree[i] = subtree[u];
			if(d[i] > mxDist[subtree[i]]){
				--freq[mxDist[subtree[i]]];
				m.erase(m.find(mxDist[subtree[i]]));
				mxDist[subtree[i]] = d[i];
				++freq[mxDist[subtree[i]]];
				m.insert(mxDist[subtree[i]]);
			}
		}
		++deg[u];
		++deg[i];
		if(deg[u] == 2){
			--nodeFreq[d[u]];
		}
		++nodeFreq[d[i]];
		int mx = *(--m.end());
		int prev = *(--(--m.end()));
		if(freq[mx] == 1){
			ans.push_back(nodeFreq[mx] + nodeFreq[prev]);
		}else{
			ans.push_back(nodeFreq[mx]);
		}
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int elem : solve(n, a)){
		cout << elem << ' ';
	}
	return 0;
}