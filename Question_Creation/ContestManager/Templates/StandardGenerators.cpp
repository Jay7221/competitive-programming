#include "Array.cpp"
using namespace std;

class Graph{
	public:
		int n, m;
		vector<pair<int, int>> edges;
		vector<vector<int>> graph;
		vector<int> weights;
		Graph(){
			n = m = 0;
		}
		Graph(int n, int m){
			this -> n = n;
			this -> m = m;
		}
		void addEdge(int u, int v){
			edges.push_back({u, v});
		}
		void generate();


		friend ostream& operator<<(ostream& out, Graph &g){
			out << g.n << " " << g.m << "\n";
			for(auto [u, v] : g.edges){
				++u, ++v;
				out << u << " " << v << "\n";
			}
			return out;
		}
		friend istream& operator<<(istream& in, Graph &g){
			in >> g.n >> g.m;
			for(int i = 0; i < g.m; ++i){
				int u, v;
				in >> u >> v;
				--u, --v;
				g.addEdge(u, v);
			}
			return in;
		}
};

void Graph::generate(){
	Array<int> arr(n);
	for(int i = 0; i < n; ++i){
		arr[i] = i;
	}
	shuffle(arr);
	int cnt = m;
	int k = 1;
	while(cnt > 0){
		for(int i = k; i < n; ++i, --cnt){
			addEdge(arr[i - k], arr[i]);
		}
		++k;
	}
}


int main(){
	Graph g(4, 3);
	g.generate();
	cerr << g << '\n';
	return 0;
}
