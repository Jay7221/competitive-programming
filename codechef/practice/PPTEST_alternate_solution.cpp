#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, w;
	cin >> n >> w;
	vector<int> marks(n + 1), time(n + 1);
	for(int i = 1; i < n + 1; i++){
		int C, P, T;
		cin >> C >> P >> T;
		marks[i] = C * P;
		time[i] = T;
	}
	vector<int> max_marks(w + 1);
	// max_marks[i] denotes the maximum marks that can be obtained in i minutes
	for(int i = 1; i < n + 1; i++){
		for(int j = w; j >= time[i]; j--){
			max_marks[j] = max(max_marks[j], max_marks[j - time[i]] + marks[i]);
		}
	}
	cout << max_marks[w] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}