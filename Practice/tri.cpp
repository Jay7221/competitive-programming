#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, k;
	cin>> n >> k;
	multiset<int> m;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		m.insert(a);
	}
	for(int i = 0; i < n && m.size(); ++i){
		if(i == *m.begin()){
			m.erase(*m.begin());
			continue ;
		}
		if(k){
			m.erase(--m.end());
			--k;
		}else{
			break ;
		}
	}
	set<int> s;
	for(auto c : m)
		s.insert(c);
	cout << s.size() << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>> t;
	while(t--){
		solve();
	}
}