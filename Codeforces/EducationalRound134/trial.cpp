#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(x), b(x);
    for(int i = 0; i < x; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < x; ++i){
        cin >> b[i];
    }


    vector<vector<int> > graph(n + 1);
    vector<int> in(n + 1);
    vector<int> rank(n + 1);
    for(int i = 1; i <= n; ++i){
        rank[i] = i;
    }
    for(int i = 0; i < x; ++i){
        graph[b[i]].push_back(a[i]);
        ++in[a[i]];
    }
    priority_queue<int> q;
    for(int i = 1; i <= n; ++i){
    	if(in[i] == 0)
    		q.push(i);
    }
    vector<int> ans;
    while(q.size()){
    	int u = q.top();
    	q.pop();
    	ans.push_back(u);
    	for(auto c : graph[u]){
    		--in[c];
    		if(in[c] == 0)
    			q.push(c);
    	}
    }
    if(ans.size() != n){
    	cout << -1 << '\n';
    }else{
    	for(auto elem : ans)
    		cout << elem << ' ';
    	cout << '\n';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}