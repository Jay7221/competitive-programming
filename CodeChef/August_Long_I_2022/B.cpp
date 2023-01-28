#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int N, X, Y;
	cin >> N >> X >> Y;
	multiset<int> s;
	for(int i = 0; i < N; ++i){
		int a;
		cin >> a;
		s.insert(a);
	}
	while(Y){
		int cur = *s.begin();
		s.erase(s.begin());
		s.insert(cur ^ X);
		--Y;
		if((cur ^ X) == *s.begin()){
			break ;
		}
	}
	if(Y % 2){
		int cur = *s.begin();
		s.erase(s.begin());
		s.insert(cur ^ X);
	}
	for(auto elem : s)
		cout << elem << ' ' ;
	cout << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TESTCASES;
	cin >> TESTCASES;
	for(int testcase = 1; testcase <= TESTCASES; ++testcase){
		solve();
	}
}