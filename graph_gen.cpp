#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

using std::cout; // iostream
using std::endl;
using std::cerr; // iostream
using std::vector; // vector
using std::default_random_engine; //random
using std::uniform_int_distribution; // random
using std::find; //algorithm

class GraphGen{
  int Vertices;
  int edges;
  vector <int> *graph;
  public:
  GraphGen(){
    cerr << "Need Num of Vertices!";
  }
  GraphGen(int v){
    if(v<=0){
      cerr << "Number of Vertices must be greater than 0!";
    }
    Vertices = v;
    int max_edges = Vertices*((Vertices-1)/2);
    create_graph(max_edges);
  }

  void create_graph(int max_edges){
    edges = 0;
    graph = new vector<int>[Vertices];
    int v, u;
    default_random_engine gen;
    uniform_int_distribution<> distr(0, Vertices-1);
    for(int i =0;i<max_edges;i++){
      v=distr(gen);
      u=distr(gen);
      if(v==u){
        i-=1;
        continue;
      }
      if(find(graph[v].begin(), graph[v].end(), u) != graph[v].end()){
        continue;
      }
      graph[v].push_back(u);
      graph[u].push_back(v);
      edges+=1;
    }
  }
  void printGraph(){
    for(int i =0;i<Vertices;i++){
      cout << i << " -> {";
      if(graph[i].empty()){
        cout << "}" << endl;
        continue;
      }
      else{
        for(int j =0;j<graph[i].size();j++){
          cout << graph[i][j] << ",";
        }
        cout << "}" << endl;
      }
    }
  }
};

int main(){
  GraphGen g_gen(100);
  g_gen.printGraph();
}
