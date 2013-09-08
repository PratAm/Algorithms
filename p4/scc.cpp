#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <iterator>

using std::vector;
using std::map;
using std::list;
using std::ifstream;
using std::cout;
using std::endl;

typedef vector< vector <long> > graphData;

	class MyGraph{
		public:
			void parse_file();
	
			map< long, vector<long> > compute_scc();
			void dfs_loop(const vector< vector<long> > &graph, vector<long> &finishTime, vector<long> &leader);
			long dfs(const vector< vector<long> > &graph, long nodeIndex, vector<bool> &expanded, vector<long> &finishTime, long t, vector<long> &leader, long s);
			list<unsigned long> get_largest_components(const map< long, vector<long> > scc, long size);

			MyGraph(){
				graph.resize(nodeCount);
				reverseGraph.resize(nodeCount);
			}

		private:
			static const char FILENAME[] ;
			graphData graph;
			graphData reverseGraph;
			static const long nodeCount = 875714;

	};

	const char MyGraph::FILENAME[] = "SCC.txt";

	int main() {

			MyGraph myGraph;

			myGraph.parse_file();

			map< long, vector<long> > scc = myGraph.compute_scc();

			list<unsigned long> largestComponents = myGraph.get_largest_components(scc, 5);

			std::copy(largestComponents.begin(),largestComponents.end(),std::ostream_iterator<unsigned long>(std::cout," "));
			cout << endl;

			return 0;
	}


	void MyGraph::parse_file() {

			ifstream graphFile(FILENAME);

			long nodeIndex;
			long outIndex;

			while (graphFile >>nodeIndex >> outIndex) {
         //since we are directly accessing some index value in vector,that index must be present
				 //That is why we need to allocate vector of that size initially.
					graph[nodeIndex - 1].push_back(outIndex - 1);
					reverseGraph[outIndex-1].push_back(nodeIndex-1);
			}

	}


	map< long, vector<long> > MyGraph::compute_scc() {

			vector<long> finishTime(graph.size(), 0);
			vector<long> leader(graph.size(), 0);

			vector<long>::iterator it;
			long index = 0;
			for (it = finishTime.begin(); it != finishTime.end(); it++) {
					*it = index;
					index++;
			}

			dfs_loop(reverseGraph, finishTime, leader);

			dfs_loop(graph, finishTime, leader);

			map< long, vector<long> > scc;
			vector<long>::iterator lit;

			for (lit = leader.begin(); lit != leader.end(); lit++) {
					long nodeIndex = lit - leader.begin();

				 scc[*lit].push_back(nodeIndex);
			}

			return scc;
	}


	void MyGraph::dfs_loop(const vector< vector<long> > &graph, vector<long> &finishTime, vector<long> &leader) {

			vector<bool> expanded(graph.size(), 0);
			vector<long> loopFinishTime = finishTime;

			long t = 0;
			vector<long>::reverse_iterator it;

			for (it = loopFinishTime.rbegin(); it != loopFinishTime.rend(); it++) {
					if (!expanded[*it]) {
							t = dfs(graph, *it, expanded, finishTime, t, leader, *it);
					}
			}
	}


	long MyGraph::dfs(
			const vector< vector<long> > &graph,
			long nodeIndex,
			vector<bool> &expanded,
			vector<long> &finishTime,
			long t,
			vector<long> &leader,
			long s
	) {
			expanded[nodeIndex] = true;

			leader[nodeIndex] = s;

			vector<long>::const_iterator it;
			for (it = graph[nodeIndex].begin(); it != graph[nodeIndex].end(); it++) {
					if (!expanded[*it]) {
							t = dfs(graph, *it, expanded, finishTime, t, leader, s);
					}
			}

			finishTime[t] = nodeIndex;
			t++;

			return t;
	}


	list<unsigned long> MyGraph::get_largest_components(const map< long, vector<long> > scc, long size) {

			list<unsigned long> largest(size, 0);

			map< long, vector<long> >::const_iterator it;
			for (it = scc.begin(); it != scc.end(); it++) {
					list<unsigned long>::iterator lit;
					for (lit = largest.begin(); lit != largest.end(); lit++) {
							if (*lit < it->second.size()) {
									largest.insert(lit, it->second.size());
									largest.pop_back();
									break;
							}
					}
			}

			return largest;
	}
