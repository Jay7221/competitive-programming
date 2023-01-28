#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> child_size(n);		// number of children ith node has
	for(int i = 0; i < n - 1; i++){
		int p;
		cin >> p;
		p--;
		child_size[p]++;
	}
	int n = child_size.size();
	priority_queue<int> siblings;
	for(auto c : child_size){
		siblings.push(c);
	}
	int cur_time = 0;
	while(!siblings.empty()){
		int k = siblings.top();
		
		cur_time++;
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