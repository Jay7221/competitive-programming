#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, x;
	int INF = 1e9 + 7;
	cin >> a >> b >> x;
	int minCost[x + 2];
	for(int i = 0; i < x + 2; ++i){
		minCost[i] = INF;
	}
	minCost[1] = 0;
	for(int i = 2; i < x + 2; ++i){
		if(i % a == 0){
			minCost[i] = min(minCost[i], minCost[i / a] + 1);
		}
		if(i > b){
			minCost[i] = min(minCost[i], 1 + minCost[i - b]);
		}
	}
	int ans = minCost[x];
	if(ans == INF){
		ans = -1;
	}
	cout << ans << '\n';
	return 0;
}
