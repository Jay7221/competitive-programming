#include<bits/stdc++.h>
using namespace std;
#define ll long long
void reverse(vector<int> &v, int l, int r){
	if(l < 0){
		return;
	}
	if(r + 1 > v.size()){
		return;
	}
	while(l < r){
		swap(v[l], v[r]);
		++l;
		--r;
	}
}
vector<int> apply(vector<int> p, int l, int r){
	reverse(p, l, r);
	int n = p.size();
    vector<int> v;
    for(int i = r + 1; i < n; ++i){
        v.push_back(p[i]);
    }
    for(int i = l; i <= r; ++i){
        v.push_back(p[i]);
    }
    for(int i = 0; i < l; ++i){
        v.push_back(p[i]);
    }
    return v;
}
int get_max(vector<int> &v){
	int ind = 0;
	for(int i = 1; i < v.size(); ++i){
		if(v[i] > v[ind]){
			ind = i;
		}
	}
	return ind;
}
void solve(){
    int n;
    cin >> n;
    vector<int> p(n), ind(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        ind[p[i]] = i;
    }
    if(n > 1){
    	if((ind[n] != 0) && (ind[n] != n - 1)){
    		int r = ind[n] - 1;
    		int l = r;
    		while((l > 0) && (p[l - 1] > p[0])){
    			--l;
    		}
    		p = apply(p, l, r);
    	}else if(ind[n] == n - 1){
    		if(p[0] > p[n - 2]){
    			p = apply(p, n - 1, n - 1);
    		}else{
    			int r = n - 2;
    			int l = r;
	    		while((l > 0) && (p[l - 1] > p[0])){
	    			--l;
	    		}
	    		p = apply(p, l, r);
    		}
    	}else{
    		if(ind[n - 1] != n - 1){
    			int l, r;
    			l = r = ind[n - 1] - 1;
    			p = apply(p, l, r);
    		}else{
    			p = apply(p, n - 1, n - 1);
    		}
    	}
    }
    for(int elem : p){
        cout << elem << ' ';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
