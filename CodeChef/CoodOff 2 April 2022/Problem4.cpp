#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (int)(1e9 + 8)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
struct min_seg_tree{
	int n;
	vector<int> tree;
	min_seg_tree(int s){
		n = 1;
		while(n < s)
			n *= 2;
		tree.resize(2 * n, MAX);
	}
	min_seg_tree(int s, vector<int> arr){
		n = 1;
		while(n < s)
			n *= 2;
		tree.resize(2 * n, MAX);
		for(int i = 0; i < s; i++)
			tree[i + n] = arr[i];
		for(int k = n - 1; k > 0; k--)
			tree[k] = min(tree[2 * k], tree[2 * k + 1]);
	}
	int min_range(int a, int b){
		a += n;		b += n;
		int ans = MAX;
		while(a <= b){
			if(a % 2 == 1)
				ans = min(ans, tree[a++]);
			if(b % 2 == 0)
				ans = min(ans, tree[b--]);
			a /= 2;		b /= 2;
		}
		return ans;
	}
	void change(int k, int x){
		k += n;
		tree[k] = x;
		for(k /= 2; k >= 1; k /= 2)
			tree[k] = min(tree[2 * k], tree[2 * k + 1]);
	}
};
struct max_seg_tree{
	int n;
	vector<int> tree;
	max_seg_tree(int s){
		n = 1;
		while(n < s)
			n *= 2;
		tree.resize(2 * n, 0);
	}
	max_seg_tree(int s, vector<int> arr){
		n = 1;
		while(n < s)
			n *= 2;
		tree.resize(2 * n, 0);
		for(int i = 0; i < s; i++)
			tree[i + n] = arr[i];
		for(int i = n - 1; i > 0; i--)
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	}
	int max_range(int a, int b){
		int ans = 0;
		a += n;		b += n;
		while(a <= b){
			if(a % 2 == 1)
				ans = max(ans, tree[a++]);
			if(b % 2 == 0)
				ans = max(ans, tree[b--]);
			a /= 2;		b /= 2;
		}
		return ans;
	}
	void change(int k, int x){
		k += n;
		tree[k] = x;
		for(k /= 2; k > 0; k /= 2)
			tree[k] = max(tree[2 * k], tree[2 * k + 1]);
	}

};
void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int i= 0; i < n; i++)
		cin >> arr[i];
	vector<int> lower_b(n - 1, 0), upper_b(n - 1, MAX);
	for(int i = 0; i < n - 1; i++){
		if(arr[i] < arr[i + 1]){
			upper_b[i] = (arr[i] + arr[i + 1])/ 2;
		}if(arr[i] > arr[i + 1] ){
			lower_b[i] = (arr[i] + arr[i + 1] + 1) / 2;
		}
	}
	min_seg_tree upper_b_tree(n - 1, upper_b);
	max_seg_tree lower_b_tree(n - 1, lower_b);
	// for(int i = 0; i < n; i++)
	// 	cerr << upper_b_tree.min_range(0, i) << ' ';
	// cerr << '\n';
	// for(int i = 0; i < n; i++)
	// 	cerr << lower_b_tree.max_range(0, i) << ' ' ;
	// cerr << '\n';
	for(int i = 0; i < q; i++){
		int type;
		cin >> type;
		if(type == 1){
			int k, x;
			cin >> k >> x;
			k--;
			arr[k] = x;
			if(k < n - 1){
				// k < n - 1    =>       k + 1 < n
				if(arr[k] > arr[k + 1]){
					upper_b_tree.change(k, MAX);
					lower_b_tree.change(k, (arr[k] + arr[k + 1] + 1) / 2);
				}
				else if(arr[k] < arr[k + 1]){
					upper_b_tree.change(k, (arr[k] + arr[k + 1]) / 2);
					lower_b_tree.change(k, 0);
				}
				else{
					upper_b_tree.change(k, MAX);
					lower_b_tree.change(k, 0);
				}
			}
			if(k > 0){
				// k > 1 		=> 		k - 1 >= 0
				if(arr[k - 1] > arr[k]){
					upper_b_tree.change(k - 1, MAX);
					lower_b_tree.change(k - 1, (arr[k - 1] + arr[k] + 1) / 2);
				}
				else if(arr[k - 1] < arr[k]){
					upper_b_tree.change(k - 1, (arr[k - 1] + arr[k]) / 2);
					lower_b_tree.change(k - 1, 0);
				}
				else{
					upper_b_tree.change(k - 1, MAX);
					lower_b_tree.change(k - 1, 0);
				}
			}
		}
		if(type == 2){
			int l, r;
			cin >> l >> r;
			l--;		r--;
			if(l == r){
				cout << 0 << '\n';
				continue ;
			}
			int upper_boun = upper_b_tree.min_range(l, r - 1), lower_boun = lower_b_tree.max_range(l, r - 1);
			if(upper_boun < lower_boun)
				cout << -1 << '\n';
			else
				cout << lower_boun << '\n';
			// because    lower_boun <= x <= upper_boun
			// so minimum value of x will be lower_boun
		}
	}
}
int main(){
	int t;
	t = 1;
	while(t--){
	solve();
	}
}