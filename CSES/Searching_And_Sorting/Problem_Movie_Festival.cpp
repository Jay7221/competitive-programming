#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > times(n);
	for(int i = 0; i < n ;i++){
		int a, b;
		cin >> a >> b;
		times[i] = {b, a};
	}
	sort(times.begin(), times.end());
	int ans = 0, cur_time = 0;
	for(auto c : times){
		int b, a;
		tie(b, a) = c;
		if(a >= cur_time){
			ans++;
			cur_time = b;
		}
	}
	cout << ans << '\n';
}