#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
class QueryInterface{
	public:
		 virtual void increment(int i, int j, int val){
			 return ;
		 }
		 virtual int minimum(int i, int j){
			 return 0;
		 }
};
// Circular RMQ
class RangesSlow : public QueryInterface{
	private:
		int *arr;
		int n;
	public:
		RangesSlow(int n): n(n){
			arr = new int(n);
		}
		void increment(int i, int j, int val){
			for(int k = i; k <= j; ++k)
				arr[k] += val;
		}
		int minimum(int i, int j){
			int ans = arr[i];
			for(int k = i; k <= j; ++k)
				ans = min(ans, arr[k]);
			return ans;
		}
};
class SegmentTree : public QueryInterface{
	private:
		int n;
		int *lo, *hi, *mn, *delta;
	public:
		SegmentTree(int n) : n(n){
			lo = new int[4 * n + 1];
			hi = new int[4 * n + 1];
			mn = new int[4 * n + 1];
			delta = new int[4 * n + 1];	
			init(1, 0, n - 1);
		}
		void init(int i, int a, int b){
			lo[i] = a;
			hi[i] = b;
			if(a == b)
				return ;
			int m = (a + b) / 2;
			init(2 * i, a, m);
			init(2 * i + 1, m + 1, b);
		}
		void increment(int a, int b, int val){
			increment(1, a, b, val);
		}
		int minimum(int a, int b){
			return minimum(1, a, b);
		}
		void prop(int i){
			delta[2 * i] += delta[i];
			delta[2 * i + 1] += delta[i];
			delta[i] = 0;
		}
		void update(int i){
			mn[i] = min(mn[2 * i] + delta[2 * i], mn[2 * i + 1] + delta[2 * i + 1]);
		}
		void increment(int i, int a, int b, int val){
			if(b < lo[i] || a > hi[i])
				return ;
			if(lo[i] <= a && b <= hi[i]){
				delta[i] += val;
				return ;
			}
			prop(i);
			increment(2 * i, a, b, val);
			increment(2 * i + 1, a, b, val);
			update(i);
		}
		int minimum(int i, int a, int b){
			if(a <= lo[i] && hi[i] <= b){
				return mn[i] + delta[i];
			}
			if(b < lo[i] || hi[i] < a)
				return INF;
			prop(i);
			int minLeft = minimum(2 * i, a, b);
			int minRight = minimum(2 * i + 1, a, b);
			update(i);
			return min(minLeft, minRight);
		}
};
int main(){
	int n = 10;
	SegmentTree t(n);
	t.increment(0, 5, 1);
	t.increment(4, 9, 1);
	cout << t.minimum(4, 4) << endl;
	return 0;
}
