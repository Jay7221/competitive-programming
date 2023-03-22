#include<bits/stdc++.h>
using namespace std;
int getRand(int a, int b){
	int diff = b - a + 1;
	int ans = a + (rand() % diff);
	return ans;
}
char getRandChar(){
	char ch = 'a' + getRand(0, 25);
	return ch;
}
string getStr(int n){
	string s;
	for(int i = 0; i < n; ++i){
		s.push_back(getRandChar());
	}
	return s;
}
int main(){
	srand(time(0));
	int MAX = 1e5;
	int n = getRand(1, MAX);
	cout << n << '\n';
	cout << getStr(n) << ' ' << getStr(n) << '\n';
	return 0;
}
