#include<bits/stdc++.h>
using namespace std;
void solve(){
	int numberStudents;
	cin >> numberStudents;
	int efforts[numberStudents + 1];
	efforts[0] = 0;
	for(int student = 1; student <= numberStudents; ++student){
		cin >> efforts[student];
	}
	sort(efforts, efforts + numberStudents + 1);
	int q;
	cin >> q;
	while(q--){
		int days;
		cin >> days;
		int minStudents = 0, maxStudents = numberStudents;
		while(minStudents < maxStudents){
			int mid = (minStudents + maxStudents + 1) / 2;
			if(efforts[mid] > days){
				maxStudents = mid - 1;
			}else{
				minStudents = mid;
			}
		}
		cout << minStudents << ' ';
	}
	cout << '\n';
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("TestCases/solution.txt", "w", stdout);
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
