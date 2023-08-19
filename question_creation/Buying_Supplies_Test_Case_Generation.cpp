#include<iostream>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#define t_l (int)(1000 + 1)
#define n_l (int)(10000 + 1)
#define k_l (int)(1e5 + 1)
#define x_l (int)(1000)
#define a_l (int)(100000 + 1)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(0));
	int t = rand() % t_l;
	if(t == 0)
		t += 1;
	cout << t << '\n';
	assert(t > 0 && t < t_l);
	for(int i = 0; i < t; i++){
		int n = rand() % n_l;
		if(n == 0)
			n++;
		int x = rand() % n;
		int k = rand() % k_l;
		assert(n > x);
		assert(n > 0 && n < n_l);
		cout << n << ' ' << x + 1 << ' ' << k << '\n';
		for(int j = 0; j < n; j++){
			int a = rand() % a_l;
			a += (a == 0);
			assert(a > 0 && a < a_l);
			cout << a << ' ' ;
		}
		cout << '\n';
	}
}