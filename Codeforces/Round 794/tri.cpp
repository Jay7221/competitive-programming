#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(int i = 0; i < n; ++i){for(int j = 0; j < i + 1; ++j){cerr << a[i][j] << ' ' ;} cerr << '\n';}cerr << '\n';
int main(){
	int n = 10;
	int mx = n + 3;
	vector<vector<int> > p(mx, vector<int>(mx)), q(mx, vector<int>(mx)), r(mx, vector<int>(mx));
	p[0][0] = q[0][0] = 1;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < n; ++j){
			p[i][j] = p[i - 1][j - 1];
			if(i >= j){
				p[i][j] += p[i - j][j];
				q[i][j] = q[i - j][j] + q[i - j][j - 1];
			}
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < n; ++j){
			r[i][j] = q[i][j];
			for(int a = 1; a < i + 1; ++a){
				for(int b = 2; b <= i / a; ++b){
					if(i >= a * b && j >= b){
						if(i == 8 && j == 3)
							cerr << a << ' ' << b << ' ' << q[i - a * b][j - b] << '\n';
						r[i][j] += q[i - a * b][j - b];
					}
				}
			}
		}
	}	
	debug(p)
	debug(q)
	debug(r)
}