#include<iostream>
#include<fstream>
#include<cstring>
#include <sstream>
#include<cassert>
#include<cmath>
#include<stdlib.h>

const int VERTEX= 200;
//const int VERTEX =9;

using namespace std;

class Graph{

	public:
		void fillgraph();
		void   set(size_t r, size_t c, size_t d) {   graph[(r * _rc) + c] = d;   return;   };
		size_t get(size_t r, size_t c) const {   return graph[(r * _rc) + c];   };
    size_t get_size() const {   return _rc;   };

		Graph& remove_self_loops();
		size_t count_vertices() const;
		size_t count_edges() const;
		Graph& merge_vertices(size_t u, size_t v);

		Graph():_rc(VERTEX){
			memset(graph,0,VERTEX*VERTEX*sizeof(int));
		}

	private:
		int graph[VERTEX*VERTEX];
		size_t _rc;

};

size_t Graph::count_vertices() const
{
   size_t n = 0;

   for (size_t i = 0; i < _rc; ++i)
   {
      size_t k = 0;
      for (size_t j = 0; j < _rc; ++j)
      {
         k = k + get(i, j);
      }

      if (k > 0)
      {
         ++n;
      }
   }

   return n;
}

size_t Graph::count_edges() const
{
   size_t n = 0;

   for (size_t i = 0; i < _rc; ++i)
   {
      for (size_t j = 0; j < _rc; ++j)
      {
         n = n + get(i, j);
      }
   }

   return n;
}

void Graph::fillgraph(){
	ifstream in("kargerMinCut.txt");
//	ifstream in("cut.txt");
  std::string linetoparse;
	int vertex =0;

  if(!in)
		cout<< "error opening input file";

	for(size_t i=0;i<VERTEX;++i){
		std::getline(in,linetoparse);
		std::istringstream iss(linetoparse);

		while(iss >> vertex){
			cout << vertex <<" ";
			set(i,vertex-1,1);
		}
		cout <<"\n"<<endl;
	}

}


Graph& Graph::remove_self_loops()
{
   for (size_t i = 0; i < VERTEX; ++i)
   {
      set(i, i, 0);
   }

   return *this;
}

Graph& Graph::merge_vertices(size_t u, size_t v)
{
   if (u < _rc && v < _rc)
   {
      for (size_t i = 0; i < _rc; ++i)
      {
         size_t e = get(v, i);
         set(v, i, 0);

         size_t n = e + get(u, i);
         set(u, i, n);

         e = get(i, v);
         set(i, v, 0);

         n = e + get(i, u);
         set(i, u, n);
      }
   }

   return *this;
}

void random_contraction_algorithm(Graph& km)
{
   km.remove_self_loops();

   while (km.count_vertices() > 2)
   {
   /* Pick an edge. */
      size_t random_vertex_u = 0, random_vertex_v = 0;

      do
      {
         random_vertex_u = rand() % km.get_size();
         random_vertex_v = rand() % km.get_size();
      }
      while (km.get(random_vertex_u, random_vertex_v) == 0);

      assert(random_vertex_u != random_vertex_v);

   /* Merge both vertices. */
      km.merge_vertices(random_vertex_u, random_vertex_v);

   /* Remove self-loops. */
      km.remove_self_loops();
   }

   return;
}

ostream& operator<<(ostream& os, const Graph& km)
{

   for (size_t i = 0; i < VERTEX; ++i)
   {
      for (size_t j = 0; j < VERTEX; ++j)
      {
         os << km.get(i, j) << " ";
      }

      os << endl;
   }

   return os;
}


int main(int argc,char **argv){

	Graph graph,minimum_graph;

	graph.fillgraph();

  graph.remove_self_loops();


   if (graph.get_size() > 0)
   {
      cout << "Input vertex count: " << graph.count_vertices() << endl;
      cout << "Input edge count: " << (graph.count_edges() >> 1) << endl;

      srand((unsigned int) time(NULL));

      size_t n = graph.count_vertices();
      float ln = log((float) n);
   //   size_t runs = n * n * ln, minimum_cut = 9999999;
      size_t runs = n * n , minimum_cut = 9999999;
      
			cout<< "total Run :"<<runs<<endl;

      for (size_t i = 0; i < runs; ++i)
      {
			   cout<< "Run :"<<i<<"of"<<runs<<endl;
         Graph copy = graph;
         random_contraction_algorithm(copy);

         size_t cut = copy.count_edges();
         assert((cut % 2) == 0);

         if (cut < minimum_cut)
         {
            minimum_cut = cut;
            minimum_graph = copy;
         }
      }

      cout << "Runs: " << runs << endl;
      cout << "Output vertex count: " << minimum_graph.count_vertices() << endl;
      cout << "Output edge count: " << (minimum_graph.count_edges() >> 1) << endl;

  //    assert(minimum_cut == 6);

      if (argc > 2)
      {
         ofstream ofs;
         ofs.open(argv[2]);
         ofs << minimum_graph;
         ofs.close();
      }
   }

	
  cout<<"*************************"<<endl;
	cout << minimum_graph ;
  cout<<"*************************"<<endl;
	cout << graph ;
	return 0;

}
