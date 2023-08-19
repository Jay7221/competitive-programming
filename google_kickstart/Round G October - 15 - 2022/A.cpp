#include<iostream>
using namespace std;
void solve(){
	int N, M, P;
	cin >> M >> N >> P;
	int john = P - 1;
	int score[M][N];
	int max_score[N];
	for(int part = 0; part < M; ++part){
		for(int day = 0; day < N; ++day){
			cin >> score[part][day];
		}
	}
	for(int day = 0; day < N; ++day){
		max_score[day] = score[john][day];
	}
	for(int part = 0; part < M; ++part){
		for(int day = 0; day < N; ++day){
			max_score[day] = max(max_score[day], score[part][day]);
		}
	}
	long long ans = 0;
	for(int day = 0; day < N; ++day){
		ans += max_score[day] - score[john][day];
	}
	cout << ans << '\n';
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": " ;
		solve();
	}
	return 0;
}