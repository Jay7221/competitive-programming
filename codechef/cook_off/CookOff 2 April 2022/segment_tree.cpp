#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (int)(1e9 + 4)
struct segment_tree{
	int  n;
	vector<int> tree;
	segment_tree(int size){
		n = 1;
		while(n < size)
			n *= 2;
		tree.resize(2 * n, MAX);
	}
	int min_range(int a, int b){
		a += n; 
		b += n;
		int ans = MAX;
		while(a < b){
			if(a % 2 == 1)
				ans = min(ans, tree[a++]);
			if(b % 2 == 0)
				ans = min(ans, tree[b--]);
			a /= 2;	b /= 2;
		}
		return ans ;
	}
	void add(int k, int x){
		k += n;
		tree[k] = x;
		for(k /= 2; k >= 1; k /= 2)
			tree[k] = min(tree[2 * k], tree[2 * k + 1]);
	}
};
int main(){
	struct segment_tree a(10);
	a.add(0, 1);
	cout << a.min_range(1, 9) << '\n';
	
}