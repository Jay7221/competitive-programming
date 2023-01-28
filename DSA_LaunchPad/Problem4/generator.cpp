#include<bits/stdc++.h>
using namespace std;
const int maxT = 100;
const int maxN = 9;
const int maxK = 9;
const int minK = 0;
const int minN = 2;
const int diffN = maxN - minN;
const int diffK = maxK - minK;
#define ll long long
int testcaseNumber = 0;
void generate_testcase(){
	int n = (rand() % diffN) + minN;
	int k = (rand() % diffK) + minK;
	cout << n << ' ' << k << '\n';
}
int main(int argc, char **argv){
	string file_path = "testcase0.txt";
	if(argc > 1){
		file_path[8] = argv[1][0];
	}
	freopen(file_path.c_str(), "w", stdout);
	srand(time(0));
	int t = (rand() % maxT) + 1;
	assert(t <= maxT);
	cout << t << '\n';
	while(t--){
		generate_testcase();
	}
	return 0;
}
