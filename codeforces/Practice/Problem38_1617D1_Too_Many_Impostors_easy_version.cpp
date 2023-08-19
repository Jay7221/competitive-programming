#include<bits/stdc++.h>
using namespace std;
int query(int a, int b, int c){
	cout <<"? " << a << ' ' << b << ' ' << c << endl;
	bool ans;
	cin >> ans;
	return ans;
}
void answer(vector<int> arr){
	cout << "! " << arr.size() << ' ';
	for(int elem : arr){
		cout << elem << ' ';
	}
	cout << endl;
}
void solve(){
	int n;
	cin >> n;
	tuple<int, int, int> excess_1, excess_0;
	int impostor, non_impostor;
	for(int i = 1; i <= n; i += 3){
		if(query(i, i + 1, i + 2)){
			excess_1 = {i, i + 1, i + 2};
		}
		else{
			excess_0 = {i, i + 1, i + 2};
		}
	}
	auto proc0 = [&](){
		int x1, x2, x3, y1, y2, y3;
		tie(x1, x2, x3) = excess_0;
		tie(y1, y2, y3) = excess_1;
		if(query(y1, x2, x3) == 1){
			impostor = x1;
			return ;
		}
		if(query(y2, x2, x3) == 1){
			impostor = x1;
			return ;
		}
		if(query(y3, x2, x3) == 1){
			impostor = x1;
			return ;
		}
		impostor = x2;
	};
	auto proc1 = [&](){
		int x1, x2, x3, y1, y2, y3;
		tie(y1, y2, y3) = excess_1;
		if(query(impostor, y2, y3) == 1){
			non_impostor = y2;
		}else{
			non_impostor = y1;
		}
	};
	proc0();
	proc1();
	vector<int> arr;
	for(int i = 1; i <= n; ++i){
		if(i == impostor){
			arr.push_back(i);
		}else if(i != non_impostor){
			if(query(i, impostor, non_impostor) == 0){
				arr.push_back(i);
			}
		}
	}
	answer(arr);
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

	return 0;
}
