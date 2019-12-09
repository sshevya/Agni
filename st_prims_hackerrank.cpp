// C++ program to store data triplet in a vector 
// using user defined structure. 
#include<bits/stdc++.h> 

using namespace std; 
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
 

bool isCyclicUtil(int v, bool visited[], int parent, vector<int> adj[]) 
{ 
     
    visited[v] = true; 
    vector<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v,adj)) 
              return true; 
        } 
         else if (*i != parent) 
           return true; 
    } 
    return false; 
 
} 
  
bool isCyclic(int g_nodes,vector<int> adj[]) 
{ 
    int V=g_nodes;
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    for (int u = 0; u < V; u++) 
        if (!visited[u]) 
          if (isCyclicUtil(u, visited, -1,adj)) 
             return true; 
  
    return false; 
} 


int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    vector<tuple<int,int,int>> vec;
    int len=g_from.size(),i;
    int sum=0;
    for( i=0;i<len;i++){

        int u=g_from[i];
        int v=g_to[i];
        int wt=g_weight[i];
        vec.push_back(make_tuple(wt,u-1,v-1));
        //keeping wt first because we have tp sort acc to wt and sort function will sort        directly according to first element
    }
    vector<int> adj[g_nodes];
 

    sort(vec.begin(),vec.end());
    for(i=0;i<len;i++){
       int wt=get<0>(vec[i]);
       int u=get<1>(vec[i]);
       int v=get<2>(vec[i]);
       
    if (!count(adj[u].begin(), adj[u].end(), v)){       
       

       adj[u].push_back(v);
       adj[v].push_back(u);
       sum+=wt;
    
    if(isCyclic(g_nodes,adj)){
      
        adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
        
        sum=sum-wt;
    
        }
    }
        
    }
    
return sum;
}

int main(){

    int g_nodes, n_edges;
    cin>>g_nodes>>n_edges;
    vector<int> g_from,g_to,g_weight;
    int u,v,wt;
    for(int i=0;i<n_edges;i++){
        cin>>u>>v>>wt;
        g_from.push_back(u);
        g_to.push_back(v);
        g_weight.push_back(wt);
    }
  int c=kruskals(g_nodes,g_from,g_to,g_weight);
  cout<<c<<endl;

    return 0;
}
