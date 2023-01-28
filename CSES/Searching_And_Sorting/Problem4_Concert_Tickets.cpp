#include<bits/stdc++.h> 
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> t(m);
	multiset<int> tickets;
	for(int i = 0; i < n; i++){
		int h;
		cin >> h;
		tickets.emplace(h);
	}
	for(int i = 0; i < m; i++){
		cin >> t[i];
	}
	for(int k = 0; k < m; k++){
		if(tickets.empty()){
			cout << -1 << '\n';
			continue ;
		}
		multiset<int>::iterator it = tickets.lower_bound(t[k]);
		if(it == tickets.end()){
			it--;
		}
		if(*it > t[k]){
			if(it == tickets.begin()){
				cout << -1 << '\n';
				continue ;
			}else{
				it--;
			}
		}
		cout << *it << '\n';
		tickets.erase(it);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}