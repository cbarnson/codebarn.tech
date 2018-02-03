// Problem    : UVa 872 - Ordering
// Time limit : 3.000 seconds
// Difficulty : 3
// Author     : Cody Barnson
// Date       : Feb. 3, 2018
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<string> value;
bool hasSoln = false;

class Graph {
   
public:
   int num_nodes;
   vector<int> indeg;
   vector<int> *adj;
   Graph(int n) : num_nodes(n) {
      adj = new vector<int>[n];
      indeg.resize(n, 0);
   }

   ~Graph() {
      delete[] adj;
   }

   void addEdge(int u, int v) {
      adj[u].push_back(v);
      indeg[v]++;
   }

   void tsUtil(vector<int>& res, bool seen[]) {
      bool flag = false;
      for (int i = 0; i < num_nodes; i++) {
	 if (indeg[i] == 0 && !seen[i]) {

	    // decr
	    for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
	       indeg[*it]--;
	    }
	    res.push_back(i);
	    seen[i] = true;
	    tsUtil(res, seen);

	    // backtrack
	    seen[i] = false;
	    res.erase(res.end() - 1);

	    // incr
	    for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
	       indeg[*it]++;
	    }

	    flag = true;
	 }
      }

      if (!flag) {
	 if (!res.empty())
	    hasSoln = true;
	 for (int i = 0; i < res.size(); i++) {
	    int j = res[i];
	    cout << value[j] << " \n"[i == ((int)res.size()-1)];
	 }
      }
   }
};

void printAll(Graph& g) {
   bool *seen = new bool[g.num_nodes];
   fill(seen, seen+g.num_nodes, false);
   vector<int> res;
   g.tsUtil(res, seen);
}

int main() {

   int tc;
   cin >> tc >> ws;

   while (tc--) {

      // init
      value.clear();
      m.clear();
      hasSoln = false;
      
      string var, con;
      getline(cin >> ws, var);
      getline(cin >> ws, con);

      stringstream ss(var);
      string x;
      int id = 0;
      while (ss >> x) {
	 m[x] = id++;
	 value.push_back(x);
      }

      Graph g((int)value.size());

      stringstream css(con);
      while (css >> x) {
	 int u = m[x.substr(0, 1)];
	 int v = m[x.substr(2, 1)];
	 g.addEdge(u, v);
      }

      printAll(g);
      if (!hasSoln)
	 cout << "NO" << endl;

      if (tc)
	 cout << endl;
   }

   return 0;
}
