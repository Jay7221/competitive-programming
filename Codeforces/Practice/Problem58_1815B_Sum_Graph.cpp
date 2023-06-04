#include<bits/stdc++.h>
using namespace std;
#define ll long long
int query1(int x){
    cout << "+ " << x << endl;
    int response;
    cin >> response;
    return response;
}
int query2(int i, int j){
    cout << "? " << i << " " << j << endl;
    int response;
    cin >> response;
    return response;
}
int answer(vector<int> v1, vector<int> v2){
    cout << "! ";
    for(int elem : v1){
        cout << elem << ' ';
    }
    for(int elem : v2){
        cout << elem << ' ';
    }
    cout << endl;
    int response;
    cin >> response;
    return response;
}
void debug(vector<int> v){
    for(int elem : v){
        cerr << elem << ' ' ;
    }
    cerr << '\n';
}
void solve(){
    int n;
    cin >> n;
    if(n == 2){
        vector<int> v1 = {1, 2}, v2 = {2, 1};
        answer(v1, v2);
        return;
    }
    query1(n + 1);
    query1(n + 2);
    vector<int> p1(n), p2(n);
    int endpoint = 1, mx_dist = 0;
    for(int i = 2; i <= n; ++i){
        int tmp = query2(1, i);
        if(tmp > mx_dist){
            mx_dist = tmp;
            endpoint = i;
        }
    }
    vector<int> v(n);
    v[0] = endpoint;
    for(int i = 1; i <= n; ++i){
        if(i != endpoint){
            int dist = query2(endpoint, i);
            v[dist] = i;
        }
    }
    int cnt;
    cnt = 1;
    for(int i = 0; i < n; i += 2){
        p1[v[i] - 1] = cnt;
        ++cnt;
    }
    cnt = n;
    for(int i = 1; i < n; i += 2){
        p1[v[i] - 1] = cnt;
        --cnt;
    }

    reverse(v.begin(), v.end());
    cnt = 1;
    for(int i = 0; i < n; i += 2){
        p2[v[i] - 1] = cnt;
        ++cnt;
    }
    cnt = n;
    for(int i = 1; i < n; i += 2){
        p2[v[i] - 1] = cnt;
        --cnt;
    }

    answer(p1, p2);
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
