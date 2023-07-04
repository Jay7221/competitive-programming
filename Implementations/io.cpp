#include<bits/stdc++.h>
using namespace std;
template<class A, class B>
ostream& operator<<(ostream &out, const pair<A, B> &p){
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
template<class A>
ostream& operator<<(ostream &out, const vector<A> &v){
    for(int i = 0; i < v.size(); ++i){
        if(i > 0){
            out << ' ';
        }
        out << v[i];
    }
    return out;
}
int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    cerr << v << '\n';
    cerr << (pair<int, int>){1, 2} << '\n';
}
