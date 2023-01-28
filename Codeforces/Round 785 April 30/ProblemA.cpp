#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int Alice = 0, Bob = 0, total = 0;
	vector<int> scores(n);
	for(int i = 0; i < n; i++){
		scores[i] = s[i] - 'a' + 1;
		total += scores[i];
	}
	if(n % 2 == 0){
		Alice = total;
		Bob = 0;
	}else{
		Alice = total - min(scores[0], scores[n - 1]);
		Bob = min(scores[0], scores[n - 1]);
	}
	if(Alice > Bob){
		cout << "Alice " << Alice - Bob << '\n';
	}else{
		cout << "Bob " << Bob - Alice << '\n';
	}
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