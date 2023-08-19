#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> notes(n);
	for(int i = 0; i < n; i++){
		cin >> notes[i];
	}
	vector<bool> possible(m + 1, 0);
	possible[0] = 1;
	for(auto c : notes){
		for(int i = m; i >= c; i--){
			possible[i] = possible[i] || possible[i - c];
		}
	}
	if(possible[m])
		cout << "Yes\n";
	else
		cout << "No\n";
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}