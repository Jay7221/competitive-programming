#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
tuple<int, int, int> FIND_MAXIMUM_CROSSING_SUBARRAY(vector<int> &A, int low, int mid, int high){
	int left_sum = -INF;
	int sum = 0;
	int max_left;
	for(int i = mid; i >= low; --i){
		sum = sum + A[i];
		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = -INF;
	sum = 0;
	int max_right;
	for(int j = mid + 1; j <= high; ++j){
		sum = sum + A[j];
		if(sum > right_sum){
			right_sum = sum;
			max_right = j;
		}
	}
	sum = left_sum + right_sum;
	return {max_left, max_right, sum};
}
tuple<int, int, int> FIND_MAXIMUM_SUBARRAY(vector<int> &A, int low, int high){
	if(high == low){
		return {low, high, A[low]};
	}
	else{
		int mid = (low + high) / 2;
		int left_low, left_high, left_sum;
		tie(left_low, left_high, left_sum) = FIND_MAXIMUM_SUBARRAY(A, low, mid);
		int right_low, right_high, right_sum;
		tie(right_low, right_high, right_sum) = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
		int cross_low, cross_high, cross_sum;
		tie(cross_low, cross_high, cross_sum) = FIND_MAXIMUM_CROSSING_SUBARRAY(A, low, mid, high);
		if(left_sum >= right_sum && left_sum >= cross_sum){
			return {left_low, left_high, left_sum};
		}
		else if(right_sum >= cross_sum){
			return {right_low, right_high, right_sum};
		}
		else{
			return {cross_low, cross_high, cross_sum};
		}
	}
}
tuple<int, int, int> FIND_MAXIMUM_SUBARRAY_BRUTE_FORCE(vector<int> &A, int low, int high){
	int n = high - low + 1;
	vector<int> PRE(n);
	PRE[0] = A[low];
	for(int i = 1; i < n; ++i){
		PRE[i] = PRE[i - 1] + A[i + low];
	}
	int left, right;
	int sum = -INF;
	for(int i = low; i <= high; ++i){
		for(int j = i; j <= high; ++j){
			int cur = PRE[j - low];
			if(i > low)
				cur = cur - PRE[i - low - 1];
			if(cur > sum){
				sum = cur;
				left = i;
				right = j;
			}
		}
	}
	return {left, right, sum};
}
tuple<int, int, int> FIND_MAXIMUM_SUBARRAY_LINEAR(vector<int> &A, int low, int high){
	int sum = -INF;
	int cur = 0;
	int i = low;
	int left, right;
	for(int j = low; j <= high; ++j){
		cur = cur + A[j];
		if(cur < A[j]){
			cur = A[j];
			i = j;
		}
		if(cur > sum){
			sum = cur;
			left = i;
			right = j;
		}
	}
	return {left, right, sum};
}

int main(){
	int n;
	cout << "Enter the number of element : ";
	cin >> n;
	cout << "Enter the array : ";
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int b, c, d;
	tie(b, c, d) = FIND_MAXIMUM_SUBARRAY(a, 0, n - 1);
	cout << b << ' ' << c << ' ' << d << endl;
	tie(b, c, d) = FIND_MAXIMUM_SUBARRAY_BRUTE_FORCE(a, 0, n - 1);
	cout << b << ' ' << c << ' ' << d << endl;
	tie(b, c, d) = FIND_MAXIMUM_SUBARRAY_LINEAR(a, 0, n - 1);
	cout << b << ' ' << c << ' ' << d << endl;
	int left, right;
	return 0;
}
