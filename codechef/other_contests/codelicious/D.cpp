#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	auto query = [&](int i, int j){
		cout << 1 << ' ' << i << ' ' << j << endl;
		string s;
		cin >> s;
		return (s == "First");
	};
	auto answer = [&](int i){
		cout << 2 << ' ' << i << endl;
		return;
	};
	int max_index = 1, cur_max_index = 1;
	for(int i = 2; i <= n; ++i){
		if(query(i, cur_max_index)){
			max_index = i;
		}else{
			cur_max_index = i;
		}
	}
	answer(max_index);
}
int main(){
	
	solve();
	
	return 0;
}