#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5;
const int maxK = 1e2;
const int maxA = 1e5;
const int minK = 1;
const int minN = 1e3;
const int minA = 0;
const int diffN = maxN - minN;
const int diffK = maxK - minK;
const int diffA = maxA - minA;
#define ll long long
int testcaseNumber = 0;
void generate_testcase(){
	int n = (rand() % diffN) + minN;
	int k = (rand() % diffK) + minK;
	assert((n >= minN) && (n <= maxN));
	assert((k >= minK) && (k <= maxK));
	cout << n << ' ' << k << '\n';
	set<int> s;
	while(s.size() < (n / 2)){
		int x = (rand() % diffA) + minA;
		s.insert(x);
	}
	vector<int> a(2 * n);
	int i = 0;
	while(i < 2 * n){
		for(auto elem : s){
			a[i] = elem;
			++i;
			if(i > 2 * n - 1)
				break ;
		}
	}
	random_shuffle(a.begin(), a.end());
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}
int main(int argc, char **argv){
	string file_path = "testcase0.txt";
	if(argc > 1){
		file_path[8] = argv[1][0];
	}
	freopen(file_path.c_str(), "w", stdout);
	srand(time(0));
	generate_testcase();
	return 0;
}
