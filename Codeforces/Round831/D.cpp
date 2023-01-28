#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	for(int i = 0; i < k; ++i)
		cin >> a[i];
	int storage = n * m - (n + m - 1);
	priority_queue<int> st;
	int cur = k;
	bool flag = true;
	for(auto elem : a){
		st.push(elem);
		if(st.size() >= (n * m - 2))
			flag = false;
		if(min(n, m) == 1 && st.size() > 1)
			flag = false;
		while(st.size() && st.top() == cur){
			--cur;
			st.pop();
		}
	}
	if(flag)
		cout << "YA\n";
	else
		cout << "TIDAK\n";
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}