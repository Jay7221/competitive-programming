#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << i << " : ";for(auto c : a[i]){cerr << c << ' ';} cerr << '\n';} cerr << '\n';
#define debug_2(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
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
	// debug_2(marks)
	// debug_2(time)
	vector<vector<int> > max_marks(n + 1, vector<int>(w + 1, 0));
	// max_marks[i][j] represents the maximum marks that can be obtained solving 
	// questions from the first i questions in at most j minutes

	// here i represents that the first i questions are considered
	for(int i = 1; i < n + 1; i++){
		// here j represents that the questions are solved in at most j minutes
		for(int j = 1; j < w + 1; j++){
			max_marks[i][j] = max(max_marks[i][j], max_marks[i - 1][j]);
			if(j - time[i] >= 0){
				max_marks[i][j] = max(max_marks[i - 1][j - time[i]] + marks[i], max_marks[i][j]);
			}
		}
	}
	// debug(max_marks)
	cout << max_marks[n][w] << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}