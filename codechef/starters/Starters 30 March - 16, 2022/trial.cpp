#include<bits/stdc++.h>
using namespace std;
#define fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define debug(a) for(int i = 0; i  < a.size(); i++){cerr << a[i] << ' ' ;} cerr << '\n';
void print_matrix(int n, int m, int col[], int x1, int y1, int x2, int y2){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == x1 && j == y1){
				cout << 1 << ' ' ;
				continue ;
			}
			if(i == x2 && j == y2){
				cout << 2 << ' ';
				continue ;
			}
			cout << col[(i + j)%2] << ' ';
		}
		cout << '\n';
	}
}
int longes_incr_subseq(vi a){
	int n = a.size();
	vi len(n);
	int max_len = 0;
	len[0] = 1;
	for(int i = 1; i < n; i++){
		len[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && len[j] + 1 > len[i]){
				len[i] = len[j] + 1;
			}
		}
		max_len = max(max_len, len[i]);
	}
	debug(len)
	return max_len;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int col[] = {1, 2};
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int p1 = (x1 + y1)%2;
	int p2 = (x2 + y2)%2;
	if(p1 == 1 && p2 == 0){
		col[0] = 2;
		col[1] = 1;
	}
	if(p1 == 0 && p2 == 1){
		col[0] = 1;
		col[1] = 2;
	}
	if(p1 == 1 && p2 == 1){
		col[0] = 3;
		col[1] = 1;
	}
	if(p1 == 0 && p2 == 0){
		col[0] = 1;
		col[1] = 3;
	}
	print_matrix(n, m, col, x1, y1, x2, y2);
}
int main(){
	vi a;
	for(int i = 0; i < 10; i++){
		int k ;
		cin >> k;
		a.push_back(k);
	}
	cout << longes_incr_subseq(a) << '\n';
	debug(a)
}