#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int ans_mn = 0, ans_mx = 0;
    for(string floor : v){
        int b = count(floor.begin(), floor.end(), '1');
        int t2 = 0;
        int t01 = 0;
        for(int i = 0; i + 1 < m; ++i){
            if((floor[i] == '1') && (floor[i + 1] == '1')){
                ++t2;
                ++i;
            }
        }
        for(int i = 0; i + 1 < m; ++i){
            if(floor[i] == '0' || floor[i + 1] == '0'){
                ++t01;
                ++i;
            }
        }
        ans_mn += b - min(m / 4, t2);
        ans_mx += b - max(0, m / 4 - t01);
    }
    cout << ans_mn << ' ' << ans_mx << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  solve();

	return 0;
}
