#include<bits/stdc++.h>
using namespace std;
int getRand(int mn, int mx){
    int diff = mx - mn + 1;
    return (mn + rand() % diff);
}
void generateTestCase(int n){
    cout << n << '\n';
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        arr[i] = getRand(1, 1000);
    }
    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
int main(){
    srand(time(0));

    int t = getRand(1, 10);
    cout << t << '\n';
    vector<int> N(t);
    vector<int> p(t + 1);
    for(int i = 0; i < t + 1; ++i){
        p[i] = getRand(1, 20 - t);
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < t; ++i){
        // p[i + 1] - p[i] = 0
        N[i] = 1 + p[i + 1] - p[i];
    }
    for(int testCase = 0; testCase < t; ++testCase){
        generateTestCase(N[testCase]);
    }
}

