#include<bits/stdc++.h>
using namespace std;
int getRandom(){
	return rand();
}
template<typename T>
T getRandom(T minimum, T maximum){
	T diff = maximum - minimum;
	T res = minimum;
	if(diff > 0){
		res += rand() % diff;
	}
	return res;
}
template<typename T>
class Array{
	public:
		int n;
		vector<T> arr;
		Array(){
			this -> n = 0;
			arr.clear();
		}
		Array(int n){
			this -> n = n;
			arr.assign(n, 0);
		}
		T& operator[] (int ind){
			if(ind > arr.size() - 1){
				throw "Index out of bounds";
			}
			return arr[ind];
		}
		int size(){
			return n;
		}
		void push_back(T x){
			arr.push_back(x);
			++n;
		}
		void pop_back(T x){
			if(n == 0){
				throw "Popping from empty array!";
			}
			arr.pop_back();
			--n;
		}

		void generate();
		void generate(T sum);
		void generate(T minimum, T maximum);
		void generate(T minimum, T maximum, T sum);


		friend ostream& operator<<(ostream& out, Array &arr){
			for(int i = 0; i < arr.size(); ++i){
				out << arr[i] << " ";
			}
			return out;
		}
		friend istream& operator>>(istream& in, Array &arr){
			for(int i = 0; i < arr.size(); ++i){
				cin >> arr[i];
			}
			return in;
		}
		friend void sort(Array<T> &arr){
			sort(arr.arr.begin(), arr.arr.end());
		}
		friend void reverse(Array<T> &arr){
			reverse(arr.arr.begin(), arr.arr.end());
		}
		friend void shuffle(Array<T> &arr){
			random_shuffle(arr.arr.begin(), arr.arr.end());
		}
};


template<typename T>
void Array<T>::generate(){
	for(int i = 0; i < n; ++i){
		arr[i] = getRandom();
	}
}
template<typename T>
void Array<T>::generate(T minimum, T maximum){
	for(int i = 0; i < n; ++i){
		arr[i] = getRandom(minimum, maximum);
	}
}
template<typename T>
void Array<T>::generate(T sum){
	T mn = 0, mx = sum;
	for(int i = 0; i < n; ++i){
		arr[i] = getRandom(mn, mx);
	}
	arr[n - 1] = sum;
	sort(*this);
	for(int i = n - 1; i > 0; --i){
		arr[i] -= arr[i - 1];
	}
}
template<typename T>
void Array<T>::generate(T minimum, T maximum, T sum){
	T rem = sum;
	assert((minimum * n <= sum) && (sum <= maximum * n));
	for(int i = 0; i < n; ++i){
		T mn = max(minimum, max(0, rem - maximum * (n - 1 - i)));
		T mx = min(maximum, rem - minimum * (n - 1 - i));
		arr[i] = getRandom(mn, mx);
		rem -= arr[i];
	}
}
