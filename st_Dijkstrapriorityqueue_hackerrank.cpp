// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;  
    list< pair<int, int> > *adj; 

public: 
    Graph(int V);
    void addEdge(int u, int v, int w); 
 
    vector<int> shortestPath(int s); 
}; 
 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

vector<int> Graph::shortestPath(int src) 
{  
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    vector<int> dist(V, INF); 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

   
    while (!pq.empty()) 
    { 
       
        int u = pq.top().second; 
        pq.pop(); 

        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            
            int v = (*i).first; 
            int weight = (*i).second; 

            if (dist[v] >= dist[u] + weight) 
            { 
                
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
vector<int> res;
   
    
    for (int i = 0; i < V; ++i){
        if(dist[i]==INF){
        res.push_back(-1); 
        }else if(dist[i]!=0){
            res.push_back(dist[i]);
            
        }
    }
        return res;
} 

int main() 
{  
int t;
cin>>t;
while(t--)
{    int V ;
    int m;
    scanf("%d%d", &V,&m);
    Graph g(V);
    int graph[V][V]={0}; 

    // making above shown graph 
     for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
        
         
            g.addEdge(u-1, v-1, w);
     }
     
     int s;
     cin>>s;
     
    
    vector<int> v=g.shortestPath(s-1);
    for (int i = 0; i < V-1; i++) {   
        printf("%d ",v[i]);
    
    }
    printf("\n");
}

    return 0; 
} 
