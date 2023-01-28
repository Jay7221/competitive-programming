#include<bits/stdc++.h>
using namespace std;
void solve(int t){
	int n;
	cin >> n;
	vector<int> a(n), ans(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	multiset<int> s;
	for(int i = 0; i < n; ++i)
		s.insert(a[i]);
	//-----------------------------------------------------------

	for(int i = 0; i < n; ++i){
		int max_mentor = 2 * a[i];
		s.erase(s.find(a[i]));
		if(s.upper_bound(max_mentor) == s.begin()){
			ans[i] = -1;
		}else{
			ans[i] = *(--s.upper_bound(max_mentor));
		}
		s.insert(a[i]);
	}




	//----------------------------------------------------------
	cout << "Case #" << t << ": ";
	for(auto elem : ans)
		cout << elem << ' ' ;
	cout << '\n';
}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve(t);
	}
}