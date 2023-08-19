#include<bits/stdc++.h>
using namespace std;
bool testCase(vector<int> &p){
    int n = p.size();
    cout << n << endl;
    int numQ = 5 * n * n;
    for(int i = 0; i < numQ; ++i){
        char type;
        cin >> type;
        if(type == '?'){
            int l, r;
            cin >> l >> r;
            --l, --r;
            int ans = 0;
            for(int i = l; i <= r; ++i){
                for(int j = i + 1; j <= r; ++j){
                    ans += (p[i] > p[j]);
                }
            }
            cout << ans << endl;
        }
        else{
            int ind;
            cin >> ind;
            --ind;
            if(p[ind] == n){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> v = {{1, 3, 2, 4}, {2, 1}, {1, 2}};
    cout << v.size() << endl;
    int testNum = 1;
    for(auto p : v){
        bool pass = testCase(p);
        if(pass){
            cerr << "# Case" << testNum << " : " << "PASS" << endl;
        }
        else{
            cerr << "# Case" << testNum << " : " << "FAIL" << endl;
        }
        ++testNum;
    }
    return 0;
}
