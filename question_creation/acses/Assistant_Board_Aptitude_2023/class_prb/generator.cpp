#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MAX = 1e9;
int randNum(int mn, int mx)
{
	if(mx < mn)
	{
		throw exception();
	}
	int diff = mx - mn + 1;
	int n = std::rand() % diff;
	n = mn + n;
	return n;
}

void generateTestCase()
{
    int n, m;
    int maxN = 1e4, maxM = 1e4;
    int maxW = 1e9;
    n = randNum(1, maxN);
    m = randNum(1, maxM);
    m = max(m, n - 1);
    ll limit = (n * 1ll * (n - 1)) / 2;
    if(limit <= maxM){
        m = min(m, (int)limit);
    }
    cout << n << ' ' << m << '\n';
    vector<int> nodes(n);
    for(int i = 0; i < n; ++i){
        nodes[i] = i + 1;
    }
    random_shuffle(nodes.begin() + 1, nodes.end() - 1);
    int cur = 0;
    vector<tuple<int, int, int>> edges;
    for(int e = 0; e < m; ++e){
        int weight = randNum(0, maxW);
        edges.push_back({nodes[cur], nodes[cur + 1], weight});
        cur = (cur + 1) % (n - 1);
    }
    //random_shuffle(edges.begin(), edges.end());
    for(auto [u, v, w] : edges){
        cout << u << ' ' << v << ' ' << w << '\n';
    }
}
int main()
{
	srand(time(0));
    int t = 10;
    cout << t << '\n';
    while(t--){
        generateTestCase();
    }
	return 0;	
}
