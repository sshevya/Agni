#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

    vector<int> adj[n],result;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    bool visited[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    list<int> q;
    vector<int> dis(n,-1);
    dis[s-1]=0;

    visited[s-1]=true;
    int p;
    q.push_back(s-1);
    while(!q.empty()){
         p=q.front();
        q.pop_front();
        vector<int>::iterator i;
        for (i = adj[p].begin(); i != adj[p].end(); i++) 
        {   
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                dis[*i]=dis[p]+6;
                q.push_back(*i); 
                
            }
            
        }
        
    }
    
     for(int i=0;i<n;i++){
            if(dis[i]!=0){
            result.push_back(dis[i]);
            }
        }

return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        edges[i].resize(2);
        int a,b;
        cin>>a>>b;
        edges[i][0] = a;
        edges[i][1] = b;
    }
    
    int s;
    cin>>s;
    vector<int> dist = bfs(n,m,edges,s);
    for(int i=0;i<n;i++)
    {
        if(i==s-1)
            continue;
        cout<<dist[i]<<" ";
    }        
    cout<<endl;
    return 0;
}
