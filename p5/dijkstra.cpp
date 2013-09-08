#include <cstdio>
#include<iostream>
#include<fstream>
#include<cstring>
#include <sstream>
#include <queue>
#include <vector>
#include<stdlib.h>

using namespace std;

#define MAX 200
#define INF (1<<30)
#define DEBUG if(1)
#define pii pair< int, int >
#define pb(x) push_back(x)
#define VERTEX 200

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > Q;

vector< pii > G[MAX];
int D[MAX];
bool F[MAX];

int main() {
    int i, u, v, w, sz;
    int nodes = VERTEX;
    int starting =1;
    string linetoparse; 

	for(size_t i=0;i<VERTEX;++i){

		std::getline(cin,linetoparse);
		std::istringstream iss(linetoparse);
    string temp,tempnew;
    std::vector<int> dump;
    iss >> u;
    DEBUG cout<<u;
		while(iss >> temp){
      std::istringstream tempiss(temp);   
       while(std::getline(tempiss,tempnew,',')){
         dump.push_back(atoi(tempnew.c_str()));
        }
      DEBUG cout<<" "<< dump[0] <<","<<dump[1]<<" "	;
			 G[u].pb(pii(dump[0],dump[1]));
       dump.clear();
      
		}
		cout <<endl;
  
	}

    for(i=1; i<=VERTEX; i++){
       D[i] = INF;
    }

    D[starting] = 0;

    Q.push(pii(starting, 0));

    while(!Q.empty()) {
        u = Q.top().first;
        Q.pop();
        if(F[u]) continue;
        sz = G[u].size();
        DEBUG printf("visiting from %d:", u);
        for(i=0; i<sz; i++) {
            v = G[u][i].first;
            w = G[u][i].second;
            if(!F[v] && D[u]+w < D[v]) {
                DEBUG printf(" %d,", v);
                D[v] = D[u] + w;
                Q.push(pii(v, D[v]));
            }
        }
        DEBUG printf("\n");
        F[u] = 1; // done with u
    }

    int result[]={7,37,59,82,99,115,133,165,188,197};
    for(i=0; i<10; i++) printf("Node %d, distance from source = %d\n", i, D[result[i]]);
    return 0;
}

