// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
    int minimumRooms(int n, vector<int> &start, vector<int> &end) {
        // code here
        vector<pair<int, int> > classes(n);
        for(int i = 0; i < n; ++i){
            classes[i] = {end[i], start[i]};
        }
        sort(classes.begin(), classes.end());
        auto debug = [&](vector<int> &v){
            for(auto c : v)
                cerr << c << ' ';
            cerr << '\n';
        };
        auto check = [&](int m){
            // cerr << m << '\n';
            bool ans = true;
            vector<int> v;
            for(auto p : classes){
                int en, st;
                tie(en, st) = p;
                // debug(v);
                auto k = lower_bound(v.begin(), v.end(), st);
                if(k == v.begin()){
                    v.push_back(en);
                }else{
                    --k;
                    *k = en;
                }
                if(v.size() > m){
                    ans = false;
                    break ;
                }
            }
            return ans;
        };
        int l = 1, r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(check(m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> start(n);
        Array::input(start,n);
        
        
        vector<int> end(n);
        Array::input(end,n);
        
        Solution obj;
        int res = obj.minimumRooms(n, start, end);
        
        cout<<res<<endl;
        
    }
}